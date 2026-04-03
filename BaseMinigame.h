#pragma once
#include <vector>
#include "LegacyGame.h" // 추상화된 기존 시스템 헤더
#include "SensorCell.h" // 추상화된 센서 데이터 헤더

namespace minigame
{
    // [Portfolio Highlight: Polymorphism & Contract]
    // Abstract base class establishing the contract for all specific mini-games.
    class BaseMinigame : public CLegacyGame
    {
    protected:
        int m_nMinigameID;
        int m_nMaxTurnCount;
        bool m_bTurnSkipping;

        std::vector<bool> m_arrResultStatus;
        std::vector<std::vector<float>> m_arrScore;

    public:
        virtual ~BaseMinigame() = default;

        // Pure virtual functions forcing implementation in derived games
        virtual void StartGame() = 0;
        virtual void EndGame() = 0;
        virtual void CalculateScore() = 0;
        virtual int OnHardwareHit(SensorCell cell) = 0;
        virtual long OnPulse(unsigned long msDelta) = 0;

        // Common behaviors
        virtual void StepChangeTurn();
        void SetTurnSkipping(bool bSkipping) { m_bTurnSkipping = bSkipping; }

    protected:
        // Lifecycle & State Management hooks
        virtual void Render(unsigned long msTicks);
        virtual void RestoreGameEnvironment();
        virtual void ClearAllThrowData();
    };
}#pragma once
