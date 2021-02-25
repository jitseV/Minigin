#pragma once
#include "Component.h"
#include "Texture2D.h"
#include "Renderer.h"

#include <string>

namespace dae
{
	class RenderComponent : public Component
	{
	public:
		RenderComponent(std::string filePath);
		virtual ~RenderComponent();

		void Update(GameObject* gameObject) override;
		void Render(const GameObject* gameObject) const override;
		void SetTexture(const std::string& filePath);


	private:
		std::shared_ptr<Texture2D> m_pTexture;

	};


}

