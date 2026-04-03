#include "UISeq_FriedEgg.h"
#include "CoreManager.h"
#include <functional>

namespace minigame
{
    UISeq_FriedEgg::UISeq_FriedEgg() : m_currentState(EggState::IDLE) {}

    bool UISeq_FriedEgg::Init()
    {
        GUIObject::Init("UI_Data/FriedEgg.ui");
        m_panPosCtrl = GetChild<ui::GUIObject*>("Pan_Pos");
        m_eggVisualCtrl = GetChild<ui::GUIImage*>("Egg_Visual");
        m_fireEffectCtrl = GetChild<ui::GUIImage*>("Fire_Effect");
        return true;
    }

    void UISeq_FriedEgg::StartFryingSequence()
    {
        m_currentState = EggState::FRYING;

        if (m_fireEffectCtrl)
        {
            m_fireEffectCtrl->Show(true);
            m_fireEffectCtrl->PlayEffectScriptList();
        }

        AudioAPI::PlayLoop("Audio/Oil_Frying.wav");

        m_fryingTimer.Enable(true);
        m_fryingTimer.Reset(); // 타이머 시작
    }

    long UISeq_FriedEgg::OnPulse(unsigned long msDelta)
    {
        // [Portfolio Highlight: Continuous Timer Evaluation]
        // 다트를 던지지 않아도 일정 시간이 초과되면 계란이 타버리도록 메인 루프에서 감시
        if (m_currentState == EggState::FRYING && m_fryingTimer.IsEnabled())
        {
            if (m_fryingTimer.GetElapsedTime() > 3500) // 3.5초 초과 시 실패(Burnt) 처리
            {
                SensorCell missCell; // 강제 Miss 처리용 더미 데이터
                EvaluateFryingState(missCell);
            }
        }
        return 0;
    }

    void UISeq_FriedEgg::EvaluateFryingState(const SensorCell& cell)
    {
        StopContinuousEffects();
        m_fryingTimer.Enable(false);

        unsigned long elapsed = m_fryingTimer.GetElapsedTime();

        // 1. 상태 분기: 정밀한 밀리초(ms) 단위의 타이머 평가
        if (elapsed > 3500)
        {
            m_currentState = EggState::FAIL_BURNT;
            TriggerResultAnimation(m_currentState, 0);
        }
        else if (elapsed > 1500)
        {
            m_currentState = EggState::SUCCESS_PERFECT;
            int calculatedScore = cell.GetCalculatedScore();
            TriggerResultAnimation(m_currentState, calculatedScore);
        }
        else
        {
            m_currentState = EggState::FAIL_RAW; // 너무 빨리 던짐
            TriggerResultAnimation(m_currentState, 0);
        }
    }

    void UISeq_FriedEgg::TriggerResultAnimation(EggState resultState, int score)
    {
        // 결과 상태에 따른 비주얼 업데이트 및 턴 종료 콜백 매핑
        // ... (생략)
    }

    void UISeq_FriedEgg::StopContinuousEffects()
    {
        AudioAPI::StopAllLoops();
        if (m_fireEffectCtrl) m_fireEffectCtrl->Show(false);
    }
}