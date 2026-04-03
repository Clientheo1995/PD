#pragma once
#include "UISequenceRoot.h"
#include <vector>

namespace minigame
{
    class UISeq_TurnOffCandle : public UISequenceRoot
    {
    protected:
        std::vector<ui::GUIObject*> m_vtEntities;
        std::vector<bool> m_bIsExtinguished;
        ui::GUIText* m_txtScoreCtrl;

    public:
        UISeq_TurnOffCandle() = default;
        ~UISeq_TurnOffCandle() override = default;

        bool Init() override;
        void SetScoreBoard(int score);
        void TriggerProjectileSequence(int entityCount);
        void RestoreGameEnvironment();

    private:
        void TriggerEntityShutdownPhase(ui::GUIObject* entity);
        void LoopEntityPostEffect(ui::GUIObject* entity);
    };
}#pragma once
