#pragma once
#include "BaseMinigame.h"
#include "UISeq_SecretBubble.h"

namespace minigame
{
    class CGame_SecretBubble : public BaseMinigame
    {
    private:
        static const int DESTRUCTION_FACTOR = 3;
        UISeq_SecretBubble* m_pSeqGameView;

    public:
        CGame_SecretBubble() = default;
        ~CGame_SecretBubble() override;

        void Init() override;
        long OnPulse(unsigned long msDelta) override;
        int OnHardwareHit(SensorCell cell) override;

    private:
        void CalculateScore() override;
    };
}