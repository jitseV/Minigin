#pragma once
#include "Component.h"
#include "GameObject.h"
#include "TextComponent.h"

namespace dae
{

	class FpsComponent : public Component
	{
	public:
		FpsComponent(TextComponent* pTextComponent, const float timePerDraw = 1.0f);
		~FpsComponent() = default;

		void Update(GameObject* gameObject) override;
		void Render(const GameObject*) const override;

	private:
		TextComponent* m_pTextComponent; //not owner
		float m_FrameCounter;
		float m_TimeCounter;
		const float m_TimePerDraw;
	};

}

