#pragma once
#include "UISequenceRoot.h"
#include <vector>

namespace minigame
{
    class UISeq_HitTheTarget : public UISequenceRoot
    {
    protected:
        ui::GUIObject* m_targetPosCtrl;

        ATimer m_rotationTimer;
        float m_fAngle;
        int m_nRotationSpeed;

        std::vector<int> m_scoreHistory;
        std::vector<int> m_hitPositionHistory;

    public:
        UISeq_HitTheTarget();
        ~UISeq_HitTheTarget() override = default;

        bool Init() override;
        long OnPulse(unsigned long msDelta) override;
        bool ApplyHitLogic(const SensorCell& cell);

        void Serialize(std::vector<char>& buffer) const;
        bool Unserialize(const std::pair<const void*, size_t>& data);

    private:
        int CalculateHitSector(float currentAngle, int targetIndex);
        void SyncHardwareLEDs(float currentAngle);
        void TriggerScoreEffect(int score, int multiplier);
    };
}#pragma once
