#include "CGame_FriedShrimp.h"

namespace minigame
{
    void CGame_FriedShrimp::StartGame()
    {
        m_arrScore.clear();
        for (int i = 0; i < PLAYER_MANAGER.GetMemberCount(); i++)
        {
            std::vector<float> vec(MANAGER->GetMaxThrowCount(), -1.0f);
            m_arrScore.push_back(vec);
        }
    }

    void CGame_FriedShrimp::CalculateScore()
    {
        int playerIndex = MANAGER->GetActivePlayerIndex();
        float totalScore = 0;

        for (int i = 0; i < m_nMaxTurnCount; i++)
        {
            if (m_arrScore[playerIndex][i] == -1.0f) continue;

            if (i == 0) totalScore = m_arrScore[playerIndex][i];
            else totalScore *= m_arrScore[playerIndex][i]; // °ö¼À ´©Àû Àû¿ë
        }
        SetScore(totalScore);
    }

    int CGame_FriedShrimp::OnHardwareHit(SensorCell cell)
    {
        if (m_pSeqGameView) m_pSeqGameView->TriggerHitSequence(cell);
        return 1;
    }
}