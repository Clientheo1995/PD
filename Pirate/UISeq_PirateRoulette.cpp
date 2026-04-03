#include "UISeq_PirateRoulette.h"
#include <functional>

namespace minigame
{
    bool UISeq_PirateRoulette::Init()
    {
        GUIObject::Init("UI_Data/PirateRoulette.ui");
        m_barrelCtrl = GetChild<ui::GUIObject*>("Barrel");
        m_pirateCtrl = GetChild<ui::GUIObject*>("Pirate_Character");

        for (int i = 1; i <= 20; i++)
        {
            m_vtSwords.push_back(GetChild<ui::GUIImage*>("Sword_" + std::to_string(i)));
        }
        return true;
    }

    void UISeq_PirateRoulette::TriggerEventSequence(bool isFatalHit)
    {
        if (isFatalHit)
            PlaySuspenseShiver();
        else
            FinalizeTurn();
    }

    void UISeq_PirateRoulette::PlaySuspenseShiver()
    {
        if (m_barrelCtrl)
        {
            m_barrelCtrl->PlayEffectScript("Anim_Shiver");
            m_barrelCtrl->SetCallback_EndEffect(std::bind(&UISeq_PirateRoulette::PlayEjectionPhaseOne, this));
        }
    }

    bool UISeq_PirateRoulette::UnserializeVisualState(const std::vector<uint8_t>& historicalRecord)
    {
        for (auto* pSword : m_vtSwords)
        {
            if (pSword) pSword->Show(false);
        }

        for (int sectorHit : historicalRecord)
        {
            if (sectorHit > 0 && sectorHit <= m_vtSwords.size())
            {
                m_vtSwords[sectorHit - 1]->Show(true);
            }
        }
        return true;
    }
}