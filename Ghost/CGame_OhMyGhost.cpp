#include "CGame_OhMyGhost.h"
#include "CoreManager.h"
#include <cstring>

namespace minigame
{
    void CGame_OhMyGhost::Init()
    {
        BaseMinigame::Init();
        m_nMaxTurnCount = 3;
        GenerateRandomTargetZones();

        m_pSeqGameView = new UISeq_OhMyGhost();
        m_pSeqGameView->Init();
        MANAGER->SetCurSeq(m_pSeqGameView);
    }

    void CGame_OhMyGhost::GenerateRandomTargetZones()
    {
        bool isZoneActive = true;
        for (int i = 0; i < TARGET_ZONE_COUNT; i++)
        {
            m_bActiveZones[i] = isZoneActive;
            isZoneActive = !isZoneActive;
        }
    }

    int CGame_OhMyGhost::OnHardwareHit(SensorCell cell)
    {
        int hitIndex = cell.GetSectorIndex();
        bool isHitSuccess = m_bActiveZones[hitIndex];

        m_pSeqGameView->TriggerHitSequence(isHitSuccess);

        SetNextStep(Step::WAIT_FOR_ANIMATION);
        return 1;
    }

    void CGame_OhMyGhost::Serialize(std::vector<char>& buffer) const
    {
        super::Serialize(buffer);
        System::PushToken(buffer, "Unthrow");
        for (int i = 0; i < TARGET_ZONE_COUNT; i++)
        {
            System::PushToBuffer(buffer, m_bActiveZones[i]);
        }
        if (m_pSeqGameView) m_pSeqGameView->Serialize(buffer);
    }
}