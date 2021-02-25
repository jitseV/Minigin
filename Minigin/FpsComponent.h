#pragma once
#include "Component.h"
#include "GameObject.h"
#include "TextComponent.h"

namespace dae
{

	class FpsComponent : public Component
	{
	public:
		FpsComponent();
		~FpsComponent() = default;

		void Update(GameObject* gameObject) override;
		void Render(const GameObject*) const override;

	private:
		TextComponent* m_pTextComponent; //not owner


	};

}

