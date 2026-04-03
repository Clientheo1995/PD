#include "CGame_PirateRoulette.h"
#include "CoreManager.h"
#include <algorithm>

namespace minigame
{
    CGame_PirateRoulette::~CGame_PirateRoulette()
    {
        delete m_pSeqGameView;
    }

    void CGame_PirateRoulette::Init()
    {
        BaseMinigame::Init();
        m_nMaxTurnCount = 1;

        PrecalculateDeterministicState();

        m_pSeqGameView = new UISeq_PirateRoulette();
        m_pSeqGameView->Init();
        MANAGER->SetCurSeq(m_pSeqGameView);
    }

    void CGame_PirateRoulette::PrecalculateDeterministicState()
    {
        std::vector<int> vRounds = { 0, 0, 1, 1, 1, 1, 1, 2, 2 };
        std::shuffle(vRounds.begin(), vRounds.end(), RNG_MANAGER->GetEngine());

        m_nTriggerRound = vRounds[0];
        m_nTargetPlayerIndex = RNG_MANAGER->GetRandomRange(0, PLAYER_MANAGER.GetMemberCount() - 1);
    }

    int CGame_PirateRoulette::OnHardwareHit(SensorCell cell)
    {
        m_arrThrowRecord.push_back(cell.GetSectorID());

        bool isFatal = (MANAGER->GetActivePlayerIndex() == m_nTargetPlayerIndex);
        m_pSeqGameView->TriggerEventSequence(isFatal);

        SetNextStep(Step::WAIT_FOR_ANIMATION);
        return 1;
    }
}