#pragma once
#include "UISequenceRoot.h"

namespace minigame
{
    class UISeq_OhMyGhost : public UISequenceRoot
    {
    protected:
        ui::GUIImage* m_doorGlowCtrl;
        ui::GUIObject* m_ghostHandCtrl;

    public:
        UISeq_OhMyGhost() = default;
        ~UISeq_OhMyGhost() override = default;

        bool Init() override;
        void TriggerHitSequence(bool isSuccess);

        void Serialize(std::vector<char>& buffer) const;
        bool Unserialize(const std::pair<const void*, size_t>& data);

    private:
        // [Portfolio Highlight: Async Callback Chaining]
        void PlayDoorOpenEffect();
        void PlayGhostRevealEffect();
        void FinalizeTurn();
    };
}