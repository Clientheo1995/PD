#pragma once
#include "UISequenceRoot.h"

namespace minigame
{
    class UISeq_NoBullCountUp : public UISequenceRoot
    {
    protected:
        ui::GUIObject* m_characterPosCtrl;
        ui::GUIImage* m_characterWalkCtrl;
        ui::GUIImage* m_characterFlyCtrl;
        ui::GUIObject* m_boardCrackCtrl;

    public:
        UISeq_NoBullCountUp() = default;
        ~UISeq_NoBullCountUp() override = default;

        bool Init() override;
        void TriggerHitLogic(const SensorCell& cell);
        void TriggerRoundFail();
        void ResetVisualState();

    private:
        void SetCharacterState_Fly();
        void SetCharacterState_Walk();
        void SetCharacterState_Idle();
    };
}#pragma once
