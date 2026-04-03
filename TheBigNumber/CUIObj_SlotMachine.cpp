#include "CUIObj_SlotMachine.h"

namespace minigame
{
    CUIObj_SlotMachine::CUIObj_SlotMachine() : m_nCurrentActiveReelIndex(0), m_nCalculatedScore(0)
    {
        for (int i = 0; i < MAX_REEL_COUNT; i++) m_bIsReelStopped[i] = false;
    }

    bool CUIObj_SlotMachine::Init()
    {
        GUIObject::Init("UI_Data/Prefabs/SlotMachine.ui");
        return true;
    }

    void CUIObj_SlotMachine::EvaluateAndStopReel()
    {
        if (m_nCurrentActiveReelIndex >= MAX_REEL_COUNT) return;

        // 비동기 릴 정지: 타이머를 가동하여 메인 스레드 블로킹 방지
        m_bIsReelStopped[m_nCurrentActiveReelIndex] = true;
        m_reelTimer[m_nCurrentActiveReelIndex].Enable(true);
        m_reelTimer[m_nCurrentActiveReelIndex].Reset(500);

        m_nCurrentActiveReelIndex++;
        if (m_nCurrentActiveReelIndex == MAX_REEL_COUNT) CalculateFinalScore();
    }

    void CUIObj_SlotMachine::OnUpdate(unsigned long msDelta)
    {
        for (int i = 0; i < MAX_REEL_COUNT; i++)
        {
            if (m_bIsReelStopped[i] && m_reelTimer[i].IsEnabled() && m_reelTimer[i].IsExpired())
            {
                m_reelTimer[i].Enable(false);
                TriggerReelStopEffect(i);
            }
        }
    }

    void CUIObj_SlotMachine::TriggerReelStopEffect(int reelIndex)
    {
        AudioAPI::PlaySound("Audio/Slot_Clack.wav");
    }
}