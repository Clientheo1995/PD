#pragma once
#include "BaseMinigame.h"
#include "UISeq_TurnOffCandle.h"

namespace minigame
{
    class CGame_TurnOffCandle : public BaseMinigame
    {
    private:
        UISeq_TurnOffCandle* m_pSeqGameView;

    public:
        CGame_TurnOffCandle() = default;
        ~CGame_TurnOffCandle() override;

        void Init() override;
        long OnPulse(unsigned long msDelta) override;
        int OnHardwareHit(SensorCell cell) override;

    private:
        int CalculateTargetEntityCount(int rawScore);
        void CalculateScore() override;
    };
}#pragma once
