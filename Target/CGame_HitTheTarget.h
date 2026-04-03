#pragma once
#include "BaseMinigame.h"
#include "UISeq_HitTheTarget.h"

namespace minigame
{
    class CGame_HitTheTarget : public BaseMinigame
    {
        typedef BaseMinigame super;

    private:
        UISeq_HitTheTarget* m_pSeqGameView;

    public:
        CGame_HitTheTarget() = default;
        ~CGame_HitTheTarget() override;

        void Init() override;
        int OnHardwareHit(SensorCell cell) override;

        // [Portfolio Highlight: Memento Pattern]
        void Serialize(std::vector<char>& buffer) const override;
        bool Unserialize(const std::pair<const void*, size_t>& data) override;

    private:
        void CalculateScore() override;
    };
}