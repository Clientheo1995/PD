#pragma once
#include "BaseMinigame.h"
#include "UISeq_HitAndHit.h"

namespace minigame
{
    class CGame_HitAndHit : public BaseMinigame
    {
    public:
        enum class HitResultState { HOMERUN, EXCELLENT, GOOD, STRIKE, INVALID };

    private:
        HitResultState m_enCurrentState;
        UISeq_HitAndHit* m_pSeqGameView;

    public:
        CGame_HitAndHit() = default;
        ~CGame_HitAndHit() override;

        void Init() override;
        long OnPulse(unsigned long msDelta) override;
        int OnHardwareHit(SensorCell cell) override;

    private:
        void CalculateScore() override;
    };
}