#pragma once
#include "UISequenceRoot.h"

namespace minigame
{
    class UISeq_BreakingWalnuts : public UISequenceRoot
    {
    private:
        enum class SlotReelType { TYPE_A, TYPE_B, TYPE_C, NONE };
        enum class ObjectDamageState { ST_0_FULL, ST_1, ST_2, ST_3_BROKEN };

    protected:
        static const std::string tSCRIPT_FILEPATH_SEQ;
        static const std::string tTOKEN_SLOT_BG;
        static const std::string tTOKEN_OBJECT_DAMAGE_STATE;
        static const std::string tTOKEN_EFFECT_POPUP;

        ui::GUIImage* m_slotBgCtrl;
        ui::GUIObject* m_objectDamageCtrl;
        ui::GUIImage* m_effectPopupCtrl;

        ATimer m_hitAnimationTimer;
        ATimer m_stateTransitionTimer;

    public:
        UISeq_BreakingWalnuts() = default;
        ~UISeq_BreakingWalnuts() override = default;

        bool Init() override;
        void ApplyRule(SensorCell cell);

        void Serialize(std::vector<char>& buffer) const;
        bool Unserialize(const std::pair<const void*, size_t>& data);

    private:
        void PlayMissEffect();
        void TriggerComboAnimation();
    };
}#pragma once
