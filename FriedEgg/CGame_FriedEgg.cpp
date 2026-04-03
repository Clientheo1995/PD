#include "CGame_FriedEgg.h"
#include "CoreManager.h"

namespace minigame
{
    CGame_FriedEgg::~CGame_FriedEgg()
    {
        delete m_pSeqGameView;
    }

    void CGame_FriedEgg::Init()
    {
        BaseMinigame::Init();
        m_nMaxTurnCount = 3;

        m_pSeqGameView = new UISeq_FriedEgg();
        m_pSeqGameView->Init();
        MANAGER->SetCurSeq(m_pSeqGameView);
    }

    int CGame_FriedEgg::OnHardwareHit(SensorCell cell)
    {
        // 1. 하드웨어 입력 발생 시, UI 뷰(View)의 타이머 상태 머신으로 평가 위임
        m_pSeqGameView->EvaluateFryingState(cell);

        if (!cell.IsCenterTarget())
        {
            HardwareAPI::TriggerDynamicLEDs(cell.GetSingleScore(), MANAGER->GetActivePlayerIndex());
        }

        if (GetThrowCount() < m_nMaxTurnCount)
        {
            SetNextStep(Step::WAIT_FOR_ANIMATION);
        }

        return cell.IsValidHit() ? 1 : 0;
    }
}