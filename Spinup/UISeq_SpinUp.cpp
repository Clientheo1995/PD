#include "UISeq_SpinUp.h"

namespace minigame
{
    UISeq_SpinUp::UISeq_SpinUp()
        : m_currentMascotState(MascotState::START), m_currentVelocity(AngularVelocity::TIER_0_SLOW), m_fCurrentAngle(0.0f) {
    }

    bool UISeq_SpinUp::Init()
    {
        GUIObject::Init("UI_Data/SpinUp.ui");
        m_wheelPosCtrl = GetChild<ui::GUIObject*>("Img_Wheel_Pos");
        return true;
    }

    long UISeq_SpinUp::OnPulse(unsigned long msDelta)
    {
        if (m_rotationTimer.IsEnabled() && m_rotationTimer.IsExpired())
        {
            m_rotationTimer.Reset();

            // 상태 기반의 동적 가속도 연산
            float deltaAngle = static_cast<float>(m_currentVelocity) * (msDelta / 1000.0f);
            m_fCurrentAngle += deltaAngle;

            if (m_fCurrentAngle >= 360.0f) m_fCurrentAngle -= 360.0f;

            UpdateWheelTransform(m_fCurrentAngle);
        }
        return 0;
    }

    void UISeq_SpinUp::UpdateWheelTransform(float newAngle)
    {
        if (m_wheelPosCtrl)
        {
            DrawInfo di = m_wheelPosCtrl->GetDrawInfo();
            di.Rotate.Rotate(newAngle);
            m_wheelPosCtrl->SetDrawInfo(di);
        }
    }

    void UISeq_SpinUp::TransitionMascotState(MascotState nextState)
    {
        m_currentMascotState = nextState;

        // 시나리오 상태에 따라 각속도 티어 조절
        switch (m_currentMascotState)
        {
        case MascotState::START: m_currentVelocity = AngularVelocity::TIER_0_SLOW; break;
        case MascotState::RUN_PHASE_1: m_currentVelocity = AngularVelocity::TIER_1_MEDIUM; break;
        case MascotState::RUN_PHASE_2: m_currentVelocity = AngularVelocity::TIER_2_FAST; break;
        default: m_currentVelocity = AngularVelocity::TIER_0_SLOW; break;
        }
    }
}