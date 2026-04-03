#pragma once
#include "LegacyGame.h"
#include "SensorCell.h"

namespace minigame
{
    // [Portfolio Highlight: Facade Pattern]
    // Acts as a bridge between the legacy monolithic engine and the new modular mini-game manager.
    class CMinigameFacade : public CLegacyGame
    {
    public:
        CMinigameFacade() = default;
        virtual ~CMinigameFacade() = default;

        void Init() override;

        // Factory Method triggering dynamic allocation
        void StartMiniGame();

        // Hardware Event Router
        int OnHardwareHit(SensorCell cell) override;
    };
}