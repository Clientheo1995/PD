#pragma once
#include "BaseMinigame.h"
#include "UISeq_SpinUp.h"

namespace minigame
{
    class CGame_SpinUp : public BaseMinigame
    {
    private:
        UISeq_SpinUp* m_pSeqGameView;

    public:
        CGame_SpinUp() = default;
        ~CGame_SpinUp() override;

        void Init() override;
        long OnPulse(unsigned long msDelta) override;
        int OnHardwareHit(SensorCell cell) override;

    private:
        void CalculateScore() override;
    };
}#pragma once
