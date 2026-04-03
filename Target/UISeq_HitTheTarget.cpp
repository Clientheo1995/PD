#include "UISeq_HitTheTarget.h"
#include "CoreManager.h"
#include <cmath>
#include <functional>

namespace minigame
{
    UISeq_HitTheTarget::UISeq_HitTheTarget() : m_fAngle(0.0f), m_nRotationSpeed(18)
    {
        m_scoreHistory.assign(3, -1);
        m_hitPositionHistory.assign(3, 0);
    }

    bool UISeq_HitTheTarget::Init()
    {
        GUIObject::Init("UI_Data/HitTheTarget.ui");
        m_targetPosCtrl = GetChild<ui::GUIObject*>("Target_Pos");
        return true;
    }

    long UISeq_HitTheTarget::OnPulse(unsigned long msDelta)
    {
        if (m_rotationTimer.IsEnabled() && m_rotationTimer.IsExpired())
        {
            m_rotationTimer.Reset();

            // Calculate & apply real-time rotation to UI Component
            m_fAngle += m_nRotationSpeed;
            if (m_fAngle >= 360.0f) m_fAngle -= 360.0f;
            else if (m_fAngle <= -360.0f) m_fAngle += 360.0f;

            DrawInfo di = m_targetPosCtrl->GetDrawInfo();
            di.Rotate.Rotate(m_fAngle);
            m_targetPosCtrl->SetDrawInfo(di);

            SyncHardwareLEDs(m_fAngle);
        }
        return 0;
    }

    bool UISeq_HitTheTarget::ApplyHitLogic(const SensorCell& cell)
    {
        m_rotationTimer.Enable(false);

        // Math intersection logic
        int hitSector = CalculateHitSector(std::abs(m_fAngle), cell.GetSectorIndex());

        int throwIndex = MANAGER->GetCurrentThrowIndex();
        m_hitPositionHistory[throwIndex] = cell.GetPositionMultiplier();

        if (hitSector > 0)
        {
            int calculatedScore = hitSector * cell.GetPositionMultiplier();
            m_scoreHistory[throwIndex] = calculatedScore;

            TriggerScoreEffect(calculatedScore, cell.GetPositionMultiplier());
            return true;
        }

        m_scoreHistory[throwIndex] = 0;
        return false;
    }

    // --- State Restoration (Undo) ---
    void UISeq_HitTheTarget::Serialize(std::vector<char>& buffer) const
    {
        System::PushToBuffer(buffer, m_scoreHistory);
        System::PushToBuffer(buffer, m_hitPositionHistory);
    }

    bool UISeq_HitTheTarget::Unserialize(const std::pair<const void*, size_t>& data)
    {
        System::ExtractFromBuffer(data, m_scoreHistory);
        System::ExtractFromBuffer(data, m_hitPositionHistory);
        // 복원 로직 호출
        return true;
    }
}