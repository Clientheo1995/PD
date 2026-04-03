#pragma once
#include "UISequenceRoot.h"

namespace minigame
{
    class UISeq_FriedEgg : public UISequenceRoot
    {
    public:
        // 명시적으로 정의된 프라이팬(계란)의 생명주기 상태
        enum class EggState { IDLE, FRYING, SUCCESS_PERFECT, FAIL_RAW, FAIL_BURNT };

    protected:
        ui::GUIObject* m_panPosCtrl;
        ui::GUIImage* m_eggVisualCtrl;
        ui::GUIImage* m_fireEffectCtrl;

        EggState m_currentState;
        ATimer m_fryingTimer;

    public:
        UISeq_FriedEgg();
        ~UISeq_FriedEgg() override = default;

        bool Init() override;
        long OnPulse(unsigned long msDelta) override;

        void StartFryingSequence();
        void EvaluateFryingState(const SensorCell& cell);

    private:
        void TriggerResultAnimation(EggState resultState, int score);
        void StopContinuousEffects();
    };
}