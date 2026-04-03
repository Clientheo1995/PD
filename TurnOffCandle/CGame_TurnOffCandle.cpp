#include "CGame_TurnOffCandle.h"
#include "CoreManager.h"

namespace minigame
{
    CGame_TurnOffCandle::~CGame_TurnOffCandle()
    {
        delete m_pSeqGameView;
    }

    void CGame_TurnOffCandle::Init()
    {
        BaseMinigame::Init();
        m_nMaxTurnCount = 1;

        m_pSeqGameView = new UISeq_TurnOffCandle();
        m_pSeqGameView->Init();
        MANAGER->SetCurSeq(m_pSeqGameView);
    }

    int CGame_TurnOffCandle::CalculateTargetEntityCount(int rawScore)
    {
        if (rawScore <= 10) return 1;
        if (rawScore <= 20) return 2;
        if (rawScore <= 30) return 3;
        if (rawScore <= 40) return 4;
        if (rawScore <= 50) return 5;
        return 6;
    }

    int CGame_TurnOffCandle::OnHardwareHit(SensorCell cell)
    {
        int rawScore = cell.GetSingleScore();
        int affectedEntityCount = CalculateTargetEntityCount(rawScore);

        m_pSeqGameView->SetScoreBoard(rawScore);
        m_pSeqGameView->TriggerProjectileSequence(affectedEntityCount);

        if (!cell.IsCenterTarget())
        {
            HardwareAPI::TriggerDynamicLEDs(rawScore, MANAGER->GetActivePlayerIndex());
        }

        SetNextStep(Step::WAIT_FOR_ANIMATION);
        return 1;
    }
}