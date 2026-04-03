#pragma once
#include "UISequenceRoot.h"
#include <vector>

namespace minigame
{
    class UISeq_SecretBubble : public UISequenceRoot
    {
    protected:
        std::vector<ui::GUIObject*> m_vtDynamicEntities;
        std::vector<int> m_bIsEntityDestroyed;

        ui::GCanvas m_blurRenderCanvas;
        bool m_bRestoreBlurState;

    public:
        UISeq_SecretBubble() = default;
        ~UISeq_SecretBubble() override = default;

        bool Init() override;
        void PopDynamicEntities(int count, int score);
        void RestoreGameEnvironment();

    private:
        void InitializeDynamicEntityPool();
        void ApplyScreenBlur();
        void ClearScreenBlur();
    };
}