#pragma once
#include "BaseMinigame.h"
#include "UISeq_FriedShrimp.h"

namespace minigame
{
    class CGame_FriedShrimp : public BaseMinigame
    {
    private:
        UISeq_FriedShrimp* m_pSeqGameView;

    public:
        CGame_FriedShrimp() = default;
        ~CGame_FriedShrimp() override;

        void Init() override;
        void StartGame() override;
        long OnPulse(unsigned long msDelta) override;
        int OnHardwareHit(SensorCell cell) override;

    private:
        // 합산 규칙을 곱셈 규칙으로 재정의 (다형성)
        void CalculateScore() override;
    };
}