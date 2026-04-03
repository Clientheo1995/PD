#pragma once
#include "BaseMinigame.h"
#include "UISeq_PirateRoulette.h"

namespace minigame
{
    class CGame_PirateRoulette : public BaseMinigame
    {
    private:
        int m_nTriggerRound;
        int m_nTargetPlayerIndex;
        std::vector<uint8_t> m_arrThrowRecord;

        UISeq_PirateRoulette* m_pSeqGameView;

    public:
        CGame_PirateRoulette() = default;
        ~CGame_PirateRoulette() override;

        void Init() override;
        long OnPulse(unsigned long msDelta) override;
        int OnHardwareHit(SensorCell cell) override;

    private:
        void PrecalculateDeterministicState();
        void CalculateScore() override;
    };
}#pragma once
