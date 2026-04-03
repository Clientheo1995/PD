#include "UISeq_FriedShrimp.h"

namespace minigame
{
    UISeq_FriedShrimp::UISeq_FriedShrimp() : m_audioFryingLoop(nullptr), m_nAudioChannel(-1) {}

    UISeq_FriedShrimp::~UISeq_FriedShrimp()
    {
        StopContinuousFryingEffect();
        delete m_audioFryingLoop;
    }

    bool UISeq_FriedShrimp::Init()
    {
        GUIObject::Init("UI_Data/FriedShrimp.ui");
        m_strainerOilLoopCtrl = GetChild<ui::GUIImage*>("Strainer_Oil_Loop");
        m_audioFryingLoop = new ASound("Audio/Oil_Frying_Loop.wav");
        return true;
    }

    void UISeq_FriedShrimp::StartContinuousFryingEffect()
    {
        // 무한 반복 효과 제어 (메모리 및 채널 관리 포함)
        if (m_strainerOilLoopCtrl)
        {
            m_strainerOilLoopCtrl->Show(true);
            m_strainerOilLoopCtrl->PlayEffectScriptList();
        }

        if (m_audioFryingLoop && !AudioAPI::IsPlaying(m_nAudioChannel))
            m_nAudioChannel = AudioAPI::PlayLoop(m_audioFryingLoop);
    }

    void UISeq_FriedShrimp::StopContinuousFryingEffect()
    {
        if (m_strainerOilLoopCtrl) m_strainerOilLoopCtrl->Show(false);
        if (m_nAudioChannel != -1)
        {
            AudioAPI::Stop(m_nAudioChannel);
            m_nAudioChannel = -1;
        }
    }
}