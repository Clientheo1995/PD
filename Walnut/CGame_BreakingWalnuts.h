#pragma once
#include "BaseMinigame.h"
#include "UISeq_BreakingWalnuts.h"
#include "UISeq_RulePage.h"

namespace minigame
{
    class CGame_BreakingWalnuts : public BaseMinigame
    {
        typedef BaseMinigame super;

    private:
        UISeq_BreakingWalnuts* m_pSeqGameView;
        UISeq_RulePage* m_pSeqRuleView;

    public:
        CGame_BreakingWalnuts() = default;
        ~CGame_BreakingWalnuts() override;

        void Init() override;
        long OnPulse(unsigned long msDelta) override;
        bool OnHardwareHit(SensorCell cell) override;

        void Serialize(std::vector<char>& buffer) const override;
        bool Unserialize(const std::pair<const void*, size_t>& data) override;
    };
}