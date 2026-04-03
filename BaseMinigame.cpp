#include "BaseMinigame.h"

namespace minigame
{
    void BaseMinigame::StepChangeTurn()
    {
        // Default turn changing logic shared across most mini-games
        m_bTurnSkipping = false;
    }

    void BaseMinigame::Render(unsigned long msTicks)
    {
        // Base rendering delegation
    }

    void BaseMinigame::RestoreGameEnvironment()
    {
        // Default Undo/Rollback environment reset hook
    }

    void BaseMinigame::ClearAllThrowData()
    {
        // Prevents memory leakage or dirty data between sessions
        m_arrScore.clear();
        m_arrResultStatus.clear();
    }
}