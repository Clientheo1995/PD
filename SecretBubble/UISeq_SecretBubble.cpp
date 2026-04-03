#include "UISeq_SecretBubble.h"

namespace minigame
{
    bool UISeq_SecretBubble::Init()
    {
        GUIObject::Init("UI_Data/SecretBubble_MainScene.ui");
        m_blurRenderCanvas.Create(GetScreenWidth(), GetScreenHeight());
        InitializeDynamicEntityPool();
        return true;
    }

    void UISeq_SecretBubble::InitializeDynamicEntityPool()
    {
        // 런타임에 동적으로 프리팹을 읽어 오브젝트 풀 생성
        for (int i = 0; i < 20; i++)
        {
            ui::GUIObject* newEntity = new ui::GUIObject();
            if (i % 3 == 0) newEntity->Init("UI_Data/Prefabs/Entity_Green.ui");
            else newEntity->Init("UI_Data/Prefabs/Entity_Pink.ui");

            m_vtDynamicEntities.push_back(newEntity);
            m_bIsEntityDestroyed.push_back(0);
            AddChild(newEntity);
        }
    }

    void UISeq_SecretBubble::PopDynamicEntities(int count, int score)
    {
        ClearScreenBlur();
        // 삭제 로직 및 애니메이션 위임...
    }

    void UISeq_SecretBubble::ApplyScreenBlur()
    {
        if (m_blurRenderCanvas.IsValid())
        {
            m_bRestoreBlurState = true;
            // 렌더 타겟을 이용한 화면 블러 처리 로직
        }
    }
}