#pragma once
#include "BaseMinigame.h"
#include "UISeq_HiddenCountUp.h"
#include <vector>

namespace minigame
{
    class CGame_HiddenCountUp : public BaseMinigame
    {
    private:
        int m_nSegmentSize;
        std::vector<int> m_nLogicalSegments;
        UISeq_HiddenCountUp* m_pSeqGameView;

    public:
        CGame_HiddenCountUp() = default;
        ~CGame_HiddenCountUp() override;

        void Init() override;
        long OnPulse(unsigned long msDelta) override;
        int OnHardwareHit(SensorCell cell) override;

    private:
        void CalculateScore() override;
    };
}#pragma once
