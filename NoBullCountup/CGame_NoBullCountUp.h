#pragma once
#include "BaseMinigame.h"
#include "UISeq_NoBullCountUp.h"

namespace minigame
{
    class CGame_NoBullCountUp : public BaseMinigame
    {
    private:
        UISeq_NoBullCountUp* m_pSeqGameView;

    public:
        CGame_NoBullCountUp() = default;
        ~CGame_NoBullCountUp() override;

        void Init() override;
        long OnPulse(unsigned long msDelta) override;
        int OnHardwareHit(SensorCell cell) override;

    private:
        void CalculateScore() override;
    };
}#pragma once
