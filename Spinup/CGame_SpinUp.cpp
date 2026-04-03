#include "CGame_SpinUp.h"
#include "CoreManager.h"

namespace minigame
{
    CGame_SpinUp::~CGame_SpinUp()
    {
        delete m_pSeqGameView;
    }

    void CGame_SpinUp::Init()
    {
        BaseMinigame::Init();
        m_nMaxTurnCount = 3;

        m_pSeqGameView = new UISeq_SpinUp();
        m_pSeqGameView->Init();
        MANAGER->SetCurSeq(m_pSeqGameView);
    }

    long CGame_SpinUp::OnPulse(unsigned long msDelta)
    {
        BaseMinigame::OnPulse(msDelta);

        // 현재 상태가 플레이 중이거나 클리어 상태일 때 뷰(View)의 OnPulse 호출 (실시간 렌더링을 위함)
        if (MANAGER->GetCurStep() == Step::PLAYGAME || MANAGER->GetCurStep() == Step::GAMECLEAR)
        {
            if (m_pSeqGameView) m_pSeqGameView->OnPulse(msDelta);
        }
        return 0;
    }

    int CGame_SpinUp::OnHardwareHit(SensorCell cell)
    {
        // 1. 물리적 타격 데이터(Inner, Double, Triple 등)에 따른 사운드 피드백 분기
        switch (cell.GetPositionType())
        {
        case SectorType::INNER:
        case SectorType::OUTER:
            AudioAPI::PlaySound("Audio/DartHit_Single.wav");
            break;
        case SectorType::DOUBLE:
            AudioAPI::PlaySound("Audio/DartHit_Double.wav");
            break;
        case SectorType::TRIPLE:
            AudioAPI::PlaySound("Audio/DartHit_Triple.wav");
            break;
        }

        // 2. View(시퀀스)로 데이터 전달하여 실시간 회전 타겟과 충돌했는지 판정 (물리-렌더링 동기화)
        if (m_pSeqGameView) m_pSeqGameView->EvaluateHitAgainstRotation(cell);

        // 3. 하드웨어 LED 제어
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