#include "UISeq_HitAndHit.h"
#include <functional>

namespace minigame
{
    bool UISeq_HitAndHit::Init()
    {
        GUIObject::Init("UI_Data/HitAndHit.ui");
        m_txt_Score_1stCtrl = GetChild<ui::GUIObject*>("Txt_Score_1st");
        m_anim_HomerunCtrl = GetChild<ui::GUIObject*>("Anim_Homerun");
        return true;
    }

    void UISeq_HitAndHit::PopUpResult(int score, CGame_HitAndHit::HitResultState resultState)
    {
        int throwIndex = MANAGER->GetCurrentThrowIndex();
        if (throwIndex == 0) m_score1 = score;
        else if (throwIndex == 1) m_score2 = score;
        else m_score3 = score;

        // Zero-allocation UI 업데이트 (문자열 생성 없이 수학 연산으로 자릿수 파싱)
        if (m_txt_Score_1stCtrl)
        {
            if (score >= 100)
            {
                static_cast<ui::GUIText*>(m_txt_Score_1stCtrl->GetChild(0))->SetText(score / 100);
                static_cast<ui::GUIText*>(m_txt_Score_1stCtrl->GetChild(1))->SetText((score % 100) / 10);
            }
            else
            {
                static_cast<ui::GUIText*>(m_txt_Score_1stCtrl->GetChild(1))->SetText(score / 10);
            }
            static_cast<ui::GUIText*>(m_txt_Score_1stCtrl->GetChild(2))->SetText(score % 10);
        }

        switch (resultState)
        {
        case CGame_HitAndHit::HitResultState::HOMERUN:
            CallHomerunAnim(); break;
        case CGame_HitAndHit::HitResultState::EXCELLENT:
            CallExcellentAnim(); break;
        default:
            FinalizeTurn(); break;
        }
    }

    void UISeq_HitAndHit::CallHomerunAnim()
    {
        if (m_anim_HomerunCtrl)
        {
            ui::Safe_Show(m_anim_HomerunCtrl, true);
            m_anim_HomerunCtrl->PlayEffectScriptList();
            m_anim_HomerunCtrl->SetCallback_EndEffect(std::bind(&UISeq_HitAndHit::FinalizeTurn, this));
        }
    }
}