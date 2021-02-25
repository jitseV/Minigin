#pragma once
#include "Component.h"
#include "Font.h"
#include "Texture2D.h"
#include "GameObject.h"
namespace dae
{

	class TextComponent : public Component
	{
	public:
		TextComponent(std::string text, std::string fontPath, unsigned int fontSize);
		~TextComponent();

		void Update(GameObject* gameObject) override;
		void Render(const GameObject* gameObject) const override;

		void SetText(const std::string& text);
	private:
		bool m_NeedsUpdate;
		std::string m_Text;
		std::shared_ptr<Font> m_Font;
		std::shared_ptr<Texture2D> m_Texture;
	};

}
