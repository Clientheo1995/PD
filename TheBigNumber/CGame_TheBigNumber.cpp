#include "CGame_TheBigNumber.h"
#include "CoreManager.h"

namespace minigame
{
    CGame_TheBigNumber::~CGame_TheBigNumber()
    {
        delete m_pSeqGameView;
    }

    void CGame_TheBigNumber::Init()
    {
        BaseMinigame::Init();
        m_nMaxTurnCount = 3;

        m_pSeqGameView = new UISeq_TheBigNumber();
        m_pSeqGameView->Init();
        MANAGER->SetCurSeq(m_pSeqGameView);
    }

    int CGame_TheBigNumber::OnHardwareHit(SensorCell cell)
    {
        m_pSeqGameView->TriggerSlotStopSequence();

        if (GetThrowCount() < m_nMaxTurnCount)
            SetNextStep(Step::WAIT_FOR_ANIMATION);

        return 1;
    }
}