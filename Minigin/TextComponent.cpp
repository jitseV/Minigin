#include "MiniginPCH.h"
#include "TextComponent.h"
#include "Renderer.h"
#include "ResourceManager.h"

#include <SDL.h>
#include <SDL_ttf.h>


dae::TextComponent::TextComponent(std::string text, std::string fontPath, unsigned int fontSize)
	:Component()
	, m_NeedsUpdate{false}
	, m_Text{text}
	, m_Font{ ResourceManager::GetInstance().LoadFont("Lingua.otf", fontSize)  }
{
	const SDL_Color color = { 255,255,255 }; // only white text is supported now
	const auto surf = TTF_RenderText_Blended(m_Font->GetFont(), m_Text.c_str(), color);
	if (surf == nullptr)
	{
		throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
	}
	auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
	if (texture == nullptr)
	{
		throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
	}
	SDL_FreeSurface(surf);
	m_Texture = std::make_shared<Texture2D>(texture);
}

dae::TextComponent::~TextComponent()
{
}

void dae::TextComponent::Update(GameObject*)
{
	if(m_NeedsUpdate)
	{
		
		const SDL_Color color = { 255,255,255 }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(m_Font->GetFont(), m_Text.c_str(), color);
		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_Texture = std::make_shared<Texture2D>(texture);
		m_NeedsUpdate = false;
	}
}

void dae::TextComponent::Render(const GameObject* gameObject) const
{
	auto temp = gameObject->GetTransform().GetPosition();
	Renderer::GetInstance().RenderTexture(*m_Texture, temp.x , temp.y );
}

void dae::TextComponent::SetText(const std::string& text)
{
	m_Text = text;
	m_NeedsUpdate = true;
}
