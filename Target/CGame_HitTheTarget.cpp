#include "CGame_HitTheTarget.h"
#include "CoreManager.h"

namespace minigame
{
    CGame_HitTheTarget::~CGame_HitTheTarget() { delete m_pSeqGameView; }

    void CGame_HitTheTarget::Init()
    {
        super::Init();
        m_nMaxTurnCount = 3;

        // Dynamic Sequence Allocation
        m_pSeqGameView = new UISeq_HitTheTarget();
        m_pSeqGameView->Init();

        MANAGER->SetCurSeq(m_pSeqGameView);
    }

    int CGame_HitTheTarget::OnHardwareHit(SensorCell cell)
    {
        // Route hardware logic to the View for angular calculation
        m_pSeqGameView->ApplyHitLogic(cell);

        if (GetThrowCount() < m_nMaxTurnCount) {
            SetNextStep(Step::WAIT_FOR_NEXT_THROW);
        }
        return 1;
    }

    // [Memento Pattern Implementation]
    void CGame_HitTheTarget::Serialize(std::vector<char>& buffer) const
    {
        super::Serialize(buffer);
        // Delegate state saving to the view sequence
        if (m_pSeqGameView) m_pSeqGameView->Serialize(buffer);
    }

    bool CGame_HitTheTarget::Unserialize(const std::pair<const void*, size_t>& data)
    {
        // Reconstruct game state from buffer (Undo operation)
        if (m_pSeqGameView) return m_pSeqGameView->Unserialize(data);
        return false;
    }
}