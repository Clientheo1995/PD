#include "CoreManager.h"

namespace minigame
{
    CoreManager::CoreManager()
        : m_pCurGame(nullptr), m_enCurStep(Step::NONE)
    {
        m_tmr = new ATimer();
    }

    CoreManager::~CoreManager()
    {
        CleanUp();
        SafeDelete(m_pCurGame);
        SafeDelete(m_tmr);
    }

    // [Crucial Memory Management] Explicitly frees previous game's memory
    void CoreManager::ResetCurGame()
    {
        SafeDelete(m_pCurGame);
        m_nCurRound++;
    }

    void CoreManager::SetCurGame(BaseMinigame& game)
    {
        m_pCurGame = &game;
    }
}