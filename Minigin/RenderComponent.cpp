#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "GameObject.h"
#include "ResourceManager.h"

dae::RenderComponent::RenderComponent(std::string filePath)
	:Component()
	, m_pTexture{ nullptr }

{
	m_pTexture = ResourceManager::GetInstance().LoadTexture(filePath);
}

dae::RenderComponent::~RenderComponent()
{

}

void dae::RenderComponent::Update(GameObject* gameObject)
{
	gameObject->GetTransform();
}

void dae::RenderComponent::Render(const GameObject* gameObject) const
{
	if (m_pTexture != nullptr)
	{
		auto temp = gameObject->GetTransform();
		Renderer::GetInstance().RenderTexture(*m_pTexture, temp.GetPosition().x, temp.GetPosition().y);
	}
}

void dae::RenderComponent::SetTexture(const std::string& filePath)
{
	m_pTexture = ResourceManager::GetInstance().LoadTexture(filePath);
}
