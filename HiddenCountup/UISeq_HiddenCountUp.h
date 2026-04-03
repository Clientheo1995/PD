#pragma once
#include "UISequenceRoot.h"
#include <vector>

namespace minigame
{
    class UISeq_HiddenCountUp : public UISequenceRoot
    {
    protected:
        std::vector<ui::GUIObject*> m_vtLeftCardPosList;
        std::vector<ui::GUIObject*> m_vtRightCardPosList;

    public:
        UISeq_HiddenCountUp() = default;
        ~UISeq_HiddenCountUp() override = default;

        bool Init() override;
        void TriggerHitSequence(int logicalIndex, int multiplier);
        void TriggerFailSequence();

    private:
        void PopScoreEffect(int logicalIndex, int multiplier);
        void FinalizeCardReveal();
    };
}#pragma once
