#include "UISeq_HiddenCountUp.h"
#include <functional>

namespace minigame
{
    bool UISeq_HiddenCountUp::Init()
    {
        GUIObject::Init("UI_Data/HiddenCountUp.ui");

        for (int i = 0; i < 10; i++)
        {
            m_vtLeftCardPosList.push_back(GetChild<ui::GUIObject*>("Card_Slot_L_" + std::to_string(i + 1)));
            m_vtRightCardPosList.push_back(GetChild<ui::GUIObject*>("Card_Slot_R_" + std::to_string(i + 1)));
        }
        return true;
    }

    void UISeq_HiddenCountUp::TriggerHitSequence(int logicalIndex, int multiplier)
    {
        ui::GUIObject* targetCard = nullptr;

        if (logicalIndex < 10 && m_vtLeftCardPosList.size() > logicalIndex) {
            targetCard = m_vtLeftCardPosList[logicalIndex];
        }
        else if (logicalIndex >= 10 && m_vtRightCardPosList.size() > (logicalIndex - 10)) {
            targetCard = m_vtRightCardPosList[logicalIndex - 10];
        }

        if (targetCard)
        {
            ui::Safe_Show(targetCard, true);
            targetCard->PlayEffectScript("Anim_Flip");

            targetCard->SetCallback_EndEffect(
                std::bind(&UISeq_HiddenCountUp::PopScoreEffect, this, logicalIndex, multiplier)
            );
        }
    }

    void UISeq_HiddenCountUp::PopScoreEffect(int logicalIndex, int multiplier)
    {
        FinalizeCardReveal();
    }
}