#include "CGame_NoBullCountUp.h"
#include "CoreManager.h"

namespace minigame
{
    CGame_NoBullCountUp::~CGame_NoBullCountUp()
    {
        delete m_pSeqGameView;
    }

    void CGame_NoBullCountUp::Init()
    {
        BaseMinigame::Init();
        m_nMaxTurnCount = 3;

        m_pSeqGameView = new UISeq_NoBullCountUp();
        m_pSeqGameView->Init();
        MANAGER->SetCurSeq(m_pSeqGameView);
    }

    int CGame_NoBullCountUp::OnHardwareHit(SensorCell cell)
    {
        if (cell.IsCenterTarget())
        {
            m_pSeqGameView->TriggerRoundFail();
        }
        else
        {
            switch (cell.GetPositionMultiplier())
            {
            case 1: AudioAPI::PlaySound("Audio/Hit_Single.wav"); break;
            case 2: AudioAPI::PlaySound("Audio/Hit_Double.wav"); break;
            case 3: AudioAPI::PlaySound("Audio/Hit_Triple.wav"); break;
            }

            m_pSeqGameView->TriggerHitLogic(cell);
        }

        if (!cell.IsCenterTarget())
        {
            HardwareAPI::TriggerDynamicLEDs(cell.GetSingleScore(), MANAGER->GetActivePlayerIndex());
        }

        if (m_nThrowCount < m_nMaxTurnCount)
        {
            SetNextStep(Step::WAIT_FOR_NEXT_THROW);
        }

        return cell.IsValidHit() ? 1 : 0;
    }
}