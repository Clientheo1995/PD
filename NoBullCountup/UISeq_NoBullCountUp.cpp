#include "UISeq_NoBullCountUp.h"

namespace minigame
{
    bool UISeq_NoBullCountUp::Init()
    {
        GUIObject::Init("UI_Data/NoBullCountUp.ui");
        m_characterPosCtrl = GetChild<ui::GUIObject*>("Character_Pos");
        m_characterWalkCtrl = GetChild<ui::GUIImage*>("Character_Walk");
        m_characterFlyCtrl = GetChild<ui::GUIImage*>("Character_Fly");
        m_boardCrackCtrl = GetChild<ui::GUIObject*>("Board_Crack");
        return true;
    }

    void UISeq_NoBullCountUp::TriggerHitLogic(const SensorCell& cell)
    {
        SetCharacterState_Walk();
    }

    void UISeq_NoBullCountUp::TriggerRoundFail()
    {
        SetCharacterState_Fly();
        if (m_boardCrackCtrl)
        {
            ui::Safe_Show(m_boardCrackCtrl, true);
            m_boardCrackCtrl->PlayEffectScriptList();
        }
    }

    void UISeq_NoBullCountUp::SetCharacterState_Fly()
    {
        ui::Safe_ShowAllChild(m_characterPosCtrl, false);
        ui::Safe_Show(m_characterFlyCtrl, true);
        if (m_characterFlyCtrl) m_characterFlyCtrl->PlayEffectScriptList();
    }

    void UISeq_NoBullCountUp::ResetVisualState()
    {
        if (m_boardCrackCtrl) m_boardCrackCtrl->Show(false);
        SetCharacterState_Idle();
    }
}