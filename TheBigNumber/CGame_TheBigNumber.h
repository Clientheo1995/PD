#pragma once
#include "BaseMinigame.h"
#include "UISeq_TheBigNumber.h"

namespace minigame
{
    class CGame_TheBigNumber : public BaseMinigame
    {
    private:
        UISeq_TheBigNumber* m_pSeqGameView;

    public:
        CGame_TheBigNumber() = default;
        ~CGame_TheBigNumber() override;

        void Init() override;
        long OnPulse(unsigned long msDelta) override;
        int OnHardwareHit(SensorCell cell) override;

    private:
        void CalculateScore() override;
    };
}