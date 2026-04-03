#include "UISeq_TurnOffCandle.h"
#include <functional>

namespace minigame
{
    bool UISeq_TurnOffCandle::Init()
    {
        GUIObject::Init("UI_Data/TurnOffCandle.ui");

        for (int i = 1; i <= 6; i++)
        {
            m_vtEntities.push_back(GetChild<ui::GUIObject*>("Candle_Pos_" + std::to_string(i)));
            m_bIsExtinguished.push_back(false);
        }
        return true;
    }

    void UISeq_TurnOffCandle::TriggerProjectileSequence(int entityCount)
    {
        for (int i = 0; i < entityCount && i < m_vtEntities.size(); i++)
        {
            if (m_vtEntities[i] && !m_bIsExtinguished[i])
            {
                TriggerEntityShutdownPhase(m_vtEntities[i]);
                m_bIsExtinguished[i] = true;
            }
        }
    }

    void UISeq_TurnOffCandle::TriggerEntityShutdownPhase(ui::GUIObject* entity)
    {
        entity->PlayEffectScript("Anim_FireOff_Start");
        entity->SetCallback_EndEffect(std::bind(&UISeq_TurnOffCandle::LoopEntityPostEffect, this, entity));
    }

    void UISeq_TurnOffCandle::RestoreGameEnvironment()
    {
        for (auto* entity : m_vtEntities)
        {
            if (entity)
            {
                entity->StopEffectScriptList();
                entity->PlayEffectScript("Anim_FireOn");
            }
        }
        std::fill(m_bIsExtinguished.begin(), m_bIsExtinguished.end(), false);
    }
}