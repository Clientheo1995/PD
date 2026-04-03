#include "CGame_SecretBubble.h"
#include "CoreManager.h"

namespace minigame
{
    CGame_SecretBubble::~CGame_SecretBubble() { delete m_pSeqGameView; }

    void CGame_SecretBubble::Init()
    {
        BaseMinigame::Init();
        m_nMaxTurnCount = 3;
        m_pSeqGameView = new UISeq_SecretBubble();
        m_pSeqGameView->Init();
        MANAGER->SetCurSeq(m_pSeqGameView);
    }

    int CGame_SecretBubble::OnHardwareHit(SensorCell cell)
    {
        int rawScore = cell.GetCalculatedScore();

        // 물리 점수를 파괴해야 할 오브젝트 개수로 비례 환산
        int destructionCount = rawScore / DESTRUCTION_FACTOR;
        if (destructionCount % 2 > 0) ++destructionCount;

        if (m_pSeqGameView) m_pSeqGameView->PopDynamicEntities(destructionCount, rawScore);

        if (GetThrowCount() < m_nMaxTurnCount) SetNextStep(Step::WAIT_FOR_ANIMATION);
        return 1;
    }
}