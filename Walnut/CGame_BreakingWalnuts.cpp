#include "CGame_BreakingWalnuts.h"
#include "CoreManager.h"

namespace minigame
{
    CGame_BreakingWalnuts::~CGame_BreakingWalnuts()
    {
        SafeDelete(m_pSeqRuleView);
        SafeDelete(m_pSeqGameView);
    }

    void CGame_BreakingWalnuts::Init()
    {
        super::Init();
        m_nMaxTurnCount = 3;

        m_pSeqRuleView = new UISeq_RulePage();
        m_pSeqRuleView->Init("UI_Data/Rule_Walnuts.ui");

        m_pSeqGameView = new UISeq_BreakingWalnuts();
        m_pSeqGameView->Init();

        MANAGER->SetCurSeq(m_pSeqGameView);
    }

    long CGame_BreakingWalnuts::OnPulse(unsigned long msDelta)
    {
        super::OnPulse(msDelta);

        switch (MANAGER->GetCurStep())
        {
        case Step::DESCRIPTION:
            m_pSeqRuleView->OnPulse(msDelta);
            break;
        case Step::PLAYGAME:
        case Step::GAMECLEAR:
            m_pSeqGameView->OnPulse(msDelta);
            break;
        default:
            break;
        }
        return 0;
    }

    bool CGame_BreakingWalnuts::OnHardwareHit(SensorCell cell)
    {
        // UI/Game Sequence로 비즈니스 로직 위임 (Delegate)
        m_pSeqGameView->ApplyRule(cell);

        if (!cell.IsCenterTarget())
        {
            HardwareAPI::TriggerBlinkEffect(cell.GetTargetID());
        }

        if (m_nThrowCount < m_nMaxTurnCount)
        {
            SetNextTurn();
        }
        return true;
    }

    void CGame_BreakingWalnuts::Serialize(std::vector<char>& buffer) const
    {
        super::Serialize(buffer);
        if (m_pSeqGameView) {
            m_pSeqGameView->Serialize(buffer);
        }
    }

    bool CGame_BreakingWalnuts::Unserialize(const std::pair<const void*, size_t>& data)
    {
        if (m_pSeqGameView) {
            return m_pSeqGameView->Unserialize(data);
        }
        return false;
    }
}