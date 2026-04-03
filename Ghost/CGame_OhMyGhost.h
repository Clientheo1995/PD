#pragma once
#include "BaseMinigame.h"
#include "UISeq_OhMyGhost.h"
#include <vector>

namespace minigame
{
    // [Portfolio Highlight: Array-based State Management]
    class CGame_OhMyGhost : public BaseMinigame
    {
        typedef BaseMinigame super;

    private:
        static const int TARGET_ZONE_COUNT = 20;
        bool m_bActiveZones[TARGET_ZONE_COUNT] = { false, };

        UISeq_OhMyGhost* m_pSeqGameView;

    public:
        CGame_OhMyGhost() = default;
        ~CGame_OhMyGhost() override;

        void Init() override;
        int OnHardwareHit(SensorCell cell) override;

        void Serialize(std::vector<char>& buffer) const override;
        bool Unserialize(const std::pair<const void*, size_t>& data) override;

    private:
        void GenerateRandomTargetZones();
        void CalculateScore() override;
    };
}#pragma once
