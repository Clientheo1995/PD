#pragma once
#include "UISequenceRoot.h"
#include "CGame_HitAndHit.h"

namespace minigame
{
    class UISeq_HitAndHit : public UISequenceRoot
    {
    protected:
        ui::GUIObject* m_txt_Score_1stCtrl;
        ui::GUIObject* m_anim_HomerunCtrl;
        ui::GUIObject* m_anim_ExcellentCtrl;

        int m_score1, m_score2, m_score3;

    public:
        UISeq_HitAndHit() = default;
        ~UISeq_HitAndHit() override = default;

        bool Init() override;
        void PopUpResult(int score, CGame_HitAndHit::HitResultState resultState);

        void Serialize(std::vector<char>& buffer) const;
        bool Unserialize(const std::pair<const void*, size_t>& data);

    private:
        void CallHomerunAnim();
        void CallExcellentAnim();
        void FinalizeTurn();
    };
}#pragma once
