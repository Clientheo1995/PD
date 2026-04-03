#pragma once
#include "BaseMinigame.h"
#include "UISeq_FriedEgg.h"

namespace minigame
{
    // [Portfolio Highlight: State Machine & Life-cycle Management]
    class CGame_FriedEgg : public BaseMinigame
    {
    private:
        UISeq_FriedEgg* m_pSeqGameView;

    public:
        CGame_FriedEgg() = default;
        ~CGame_FriedEgg() override;

        void Init() override;
        int OnHardwareHit(SensorCell cell) override;

    private:
        void CalculateScore() override;
    };
}