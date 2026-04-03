#pragma once
#include "UISequenceRoot.h"

namespace minigame
{
    class UISeq_SpinUp : public UISequenceRoot
    {
    protected:
        enum class MascotState { START, RUN_PHASE_1, RUN_PHASE_2, JUMP, END };
        enum class AngularVelocity { TIER_0_SLOW = 50, TIER_1_MEDIUM = 250, TIER_2_FAST = 480 };

        ui::GUIObject* m_wheelPosCtrl;

        MascotState m_currentMascotState;
        AngularVelocity m_currentVelocity;

        float m_fCurrentAngle;
        ATimer m_rotationTimer;

    public:
        UISeq_SpinUp();
        ~UISeq_SpinUp() override = default;

        bool Init() override;
        long OnPulse(unsigned long msDelta) override;

        void EvaluateHitAgainstRotation(const SensorCell& cell);
        void TransitionMascotState(MascotState nextState);

    private:
        void UpdateWheelTransform(float deltaAngle);
    };
}#pragma once
