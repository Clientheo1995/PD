#include "UISeq_OhMyGhost.h"
#include <functional>

namespace minigame
{
    bool UISeq_OhMyGhost::Init()
    {
        GUIObject::Init("UI_Data/OhMyGhost.ui");
        m_doorGlowCtrl = GetChild<ui::GUIImage*>("Door_Glow");
        m_ghostHandCtrl = GetChild<ui::GUIObject*>("Ghost_Hand");
        return true;
    }

    void UISeq_OhMyGhost::TriggerHitSequence(bool isSuccess)
    {
        if (isSuccess) PlayDoorOpenEffect();
        else FinalizeTurn();
    }

    void UISeq_OhMyGhost::PlayDoorOpenEffect()
    {
        if (m_doorGlowCtrl)
        {
            m_doorGlowCtrl->Show(true);
            m_doorGlowCtrl->PlayEffectScriptList();

            // Chain: Wait for door glow to finish, then reveal ghost
            m_doorGlowCtrl->SetCallback_EndEffect(
                std::bind(&UISeq_OhMyGhost::PlayGhostRevealEffect, this)
            );
        }
    }

    void UISeq_OhMyGhost::PlayGhostRevealEffect()
    {
        if (m_ghostHandCtrl)
        {
            m_ghostHandCtrl->Show(true);
            m_ghostHandCtrl->PlayEffectScript("Position_Reveal");

            m_ghostHandCtrl->SetCallback_EndEffect(
                std::bind(&UISeq_OhMyGhost::FinalizeTurn, this)
            );
        }
    }

    void UISeq_OhMyGhost::FinalizeTurn()
    {
        // 턴 종료 로직 위임
    }
}