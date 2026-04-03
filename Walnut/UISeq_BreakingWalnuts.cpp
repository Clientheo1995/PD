#include "UISeq_BreakingWalnuts.h"
#include <functional>

namespace minigame
{
    const std::string UISeq_BreakingWalnuts::tSCRIPT_FILEPATH_SEQ = "UI_Data/Game_BreakingWalnuts.ui";
    const std::string UISeq_BreakingWalnuts::tTOKEN_SLOT_BG = "Slot_Bg";
    const std::string UISeq_BreakingWalnuts::tTOKEN_OBJECT_DAMAGE_STATE = "Sqc_Damage_State";

    bool UISeq_BreakingWalnuts::Init()
    {
        GUIObject::Init(tSCRIPT_FILEPATH_SEQ);
        m_slotBgCtrl = GetChild<ui::GUIImage*>(tTOKEN_SLOT_BG);
        m_objectDamageCtrl = GetChild<ui::GUIObject*>(tTOKEN_OBJECT_DAMAGE_STATE);
        return true;
    }

    void UISeq_BreakingWalnuts::ApplyRule(SensorCell cell)
    {
        if (cell.IsMiss())
        {
            PlayMissEffect();
        }
        else
        {
            ui::Safe_Show(m_objectDamageCtrl, true);
            m_objectDamageCtrl->PlayEffectScriptList();

            m_objectDamageCtrl->SetCallback_EndEffect(
                std::bind(&UISeq_BreakingWalnuts::TriggerComboAnimation, this)
            );
        }
    }

    void UISeq_BreakingWalnuts::PlayMissEffect()
    {
        m_hitAnimationTimer.Enable(false);
        m_stateTransitionTimer.Enable(false);

        if (m_effectPopupCtrl)
        {
            ui::Safe_Show(m_effectPopupCtrl, true);
            m_effectPopupCtrl->PlayEffectScriptList();
        }
        AudioAPI::PlaySound("Audio/sfx_miss.wav");
    }
}