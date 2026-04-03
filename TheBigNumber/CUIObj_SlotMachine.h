#pragma once
#include "UIObjectRoot.h"

namespace minigame
{
    class CUIObj_SlotMachine : public ui::GUIObj_Root
    {
    private:
        static const int MAX_REEL_COUNT = 3;

        ATimer m_reelTimer[MAX_REEL_COUNT];
        bool m_bIsReelStopped[MAX_REEL_COUNT];
        int m_nCurrentActiveReelIndex;
        int m_nCalculatedScore;

    public:
        CUIObj_SlotMachine();
        virtual ~CUIObj_SlotMachine() = default;

        bool Init();
        void OnUpdate(unsigned long msDelta) override;
        void EvaluateAndStopReel();
        int GetResultScore() const { return m_nCalculatedScore; }

        void Serialize(std::vector<char>& buffer) const;
        bool Unserialize(const std::pair<const void*, size_t>& data);

    private:
        void TriggerReelStopEffect(int reelIndex);
        void CalculateFinalScore();
    };
}#pragma once
