#include "CGame_HitAndHit.h"
#include "CoreManager.h"

namespace minigame
{
    CGame_HitAndHit::~CGame_HitAndHit()
    {
        delete m_pSeqGameView;
    }

    void CGame_HitAndHit::Init()
    {
        BaseMinigame::Init();
        m_nMaxTurnCount = 3;

        m_pSeqGameView = new UISeq_HitAndHit();
        m_pSeqGameView->Init();
        MANAGER->SetCurSeq(m_pSeqGameView);
    }

    int CGame_HitAndHit::OnHardwareHit(SensorCell cell)
    {
        int generatedScore = 0;
        RNG_MANAGER->ResetSeed();

        if (cell.IsPremiumCenterTarget())
        {
            m_enCurrentState = HitResultState::HOMERUN;
            generatedScore = RNG_MANAGER->GetRandomRange(210, 251);
        }
        else if (cell.IsHighMultiplierZone())
        {
            m_enCurrentState = HitResultState::EXCELLENT;
            generatedScore = RNG_MANAGER->GetRandomRange(80, 95);
        }
        else
        {
            m_enCurrentState = HitResultState::STRIKE;
            generatedScore = 0;
        }

        if (!cell.IsCenterTarget())
        {
            HardwareAPI::TriggerDynamicLEDs(cell.GetSingleScore(), MANAGER->GetActivePlayerIndex());
        }

        m_pSeqGameView->PopUpResult(generatedScore, m_enCurrentState);

        if (m_nThrowCount < m_nMaxTurnCount)
            SetNextStep(Step::WAIT_FOR_ANIMATION);

        return 1;
    }
}