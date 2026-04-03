#include "CGame_HiddenCountUp.h"
#include "CoreManager.h"

namespace minigame
{
    CGame_HiddenCountUp::~CGame_HiddenCountUp()
    {
        delete m_pSeqGameView;
    }

    void CGame_HiddenCountUp::Init()
    {
        BaseMinigame::Init();
        m_nMaxTurnCount = 3;

        for (int i = 0; i < 20; i++)
        {
            m_nLogicalSegments.push_back(i + 1);
        }
        m_nSegmentSize = m_nLogicalSegments.size();

        m_pSeqGameView = new UISeq_HiddenCountUp();
        m_pSeqGameView->Init();
        MANAGER->SetCurSeq(m_pSeqGameView);
    }

    int CGame_HiddenCountUp::OnHardwareHit(SensorCell cell)
    {
        if (cell.IsFailureCondition())
        {
            m_pSeqGameView->TriggerFailSequence();
        }
        else
        {
            for (int i = 0; i < m_nSegmentSize; i++)
            {
                if (MANAGER->GetPhysicalSensorMap()[i] == cell.GetTargetID())
                {
                    m_pSeqGameView->TriggerHitSequence(i, cell.GetMultiplier());
                    break;
                }
            }
        }

        if (m_nThrowCount < m_nMaxTurnCount)
        {
            SetNextStep(Step::WAIT_FOR_NEXT_THROW);
        }
        return 1;
    }
}