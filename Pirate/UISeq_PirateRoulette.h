#pragma once
#include "UISequenceRoot.h"
#include <vector>

namespace minigame
{
    class UISeq_PirateRoulette : public UISequenceRoot
    {
    protected:
        ui::GUIObject* m_barrelCtrl;
        ui::GUIObject* m_pirateCtrl;
        std::vector<ui::GUIImage*> m_vtSwords;

    public:
        UISeq_PirateRoulette() = default;
        ~UISeq_PirateRoulette() override = default;

        bool Init() override;
        void TriggerEventSequence(bool isFatalHit);
        bool UnserializeVisualState(const std::vector<uint8_t>& historicalRecord);

    private:
        void PlaySuspenseShiver();
        void PlayEjectionPhaseOne();
        void PlayEjectionPhaseTwo();
        void FinalizeTurn();
    };
}#pragma once
