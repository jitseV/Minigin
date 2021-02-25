#include "MiniginPCH.h"
#include "FpsComponent.h"
#include "Time.h"

dae::FpsComponent::FpsComponent()
	:Component()
	, m_pTextComponent{ nullptr }
{
}

void dae::FpsComponent::Update(GameObject* gameObject)
{

	std::string text{ "FPS: " + std::to_string(int(1.f / Time::GetInstance().GetElapsed())) };

	if (m_pTextComponent == nullptr)
	{
		m_pTextComponent = dynamic_cast<TextComponent*>(gameObject->GetComponent<TextComponent>());
	}

	m_pTextComponent->SetText(text);

}

void dae::FpsComponent::Render(const GameObject*) const
{
}
