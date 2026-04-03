#pragma once
#include "UISequenceRoot.h"

namespace minigame
{
    class UISeq_FriedShrimp : public UISequenceRoot
    {
    protected:
        ui::GUIImage* m_strainerOilLoopCtrl;
        ASound* m_audioFryingLoop;
        int m_nAudioChannel;

    public:
        UISeq_FriedShrimp();
        ~UISeq_FriedShrimp() override;

        bool Init() override;
        void TriggerHitSequence(const SensorCell& cell);
        void StartContinuousFryingEffect();
        void StopContinuousFryingEffect();

    private:
        void UpdateShrimpVisualState(int stateLevel);
    };
}#pragma once
