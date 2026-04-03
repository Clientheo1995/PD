#pragma once
#include "BaseMinigame.h"
#include <vector>

namespace minigame
{
    // [Portfolio Highlight: Global State Machine]
    // Enum class strictly defining the overall flow of the arcade machine.
    enum class Step
    {
        NONE = -1,
        INTRO,
        SELECTGAME,
        DESCRIPTION,
        PLAYGAME,
        GAMECLEAR,
        ROUNDRESULT,
        TOTALRESULT,
        END
    };

    // CoreManager acts as the central Mediator and Lifecycle Controller.
    // It strictly manages the 2GB RAM environment by controlling when 
    // games are created, stepped, and explicitly destroyed.
    class CoreManager
    {
    private:
        BaseMinigame* m_pCurGame;
        Step m_enCurStep;
        int m_nCurRound;
        ATimer* m_tmr;

        // ... (Singleton boilerplate omitted for abstraction) ...

    public:
        CoreManager();
        ~CoreManager();

        static CoreManager* GetInstance();

        void Init();
        void CleanUp();

        // [Crucial Memory Management Interfaces]
        void ResetCurGame();
        void SetCurGame(BaseMinigame& game);
        BaseMinigame* GetCurGame() const { return m_pCurGame; }

        // State Machine Routing
        Step GetCurStep() const { return m_enCurStep; }
        void SetCurStep(Step step) { m_enCurStep = step; }

        // Session Data Routing
        int GetActiveMiniGameID() const;
        int GetActivePlayerIndex() const;
        int GetCurrentThrowIndex() const;

        // Logical Mapping for Hardware Sensors
        const std::vector<int>& GetPhysicalSensorMap() const;
    };
}

// Global accessor macro widely used in C++ game engines
#define MANAGER minigame::CoreManager::GetInstance()#pragma once
