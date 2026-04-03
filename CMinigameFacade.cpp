#include "MinigameFacade.h"
#include "CoreManager.h"
// ... (Includes for specific game headers like CGame_TimeAttack, etc.)

namespace minigame
{
    void CMinigameFacade::Init()
    {
        // Initializes legacy systems first, then bootstraps the new decoupled manager
        CLegacyGame::Init();
        MANAGER->Init();
        MANAGER->SetCurStep(Step::INTRO);
    }

    // [Memory Optimization: Dynamic Factory] 
    // Instantiates mini-games strictly on-demand to respect the 2GB RAM limits.
    void CMinigameFacade::StartMiniGame()
    {
        BaseMinigame* pMiniGame = nullptr;

        switch (MANAGER->GetActiveMiniGameID())
        {
        case (int)GameType::TIME_ATTACK_MODE:
            pMiniGame = new CGame_TimeAttack();
            SetRoundLimit(1);
            break;
        case (int)GameType::ROULETTE_MODE:
            pMiniGame = new CGame_Roulette();
            SetRoundLimit(3);
            break;
        default:
            pMiniGame = new CGame_Default();
            SetRoundLimit(1);
            break;
        }

        // Bind the dynamically allocated game to the central manager
        if (pMiniGame)
        {
            MANAGER->SetCurGame(*pMiniGame);
            pMiniGame->Init();
            pMiniGame->StartGame();
        }

        MANAGER->SetCurStep(Step::DESCRIPTION);
    }

    int CMinigameFacade::OnHardwareHit(SensorCell cell)
    {
        // Safely route the physical hit to the currently active logical mini-game
        if (!MANAGER->GetCurGame()) return 0;
        return MANAGER->GetCurGame()->OnHardwareHit(cell);
    }
}