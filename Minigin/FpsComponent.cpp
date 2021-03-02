#include "MiniginPCH.h"
#include "FpsComponent.h"
#include "Time.h"

dae::FpsComponent::FpsComponent(TextComponent* pTextComponent, float timePerDraw)
	: Component()
	, m_pTextComponent{ pTextComponent }
	, m_FrameCounter{}
	, m_TimeCounter{}
	, m_TimePerDraw{timePerDraw}
{
}

void dae::FpsComponent::Update(GameObject*)
{
	++m_FrameCounter;
	m_TimeCounter += Time::GetInstance().GetElapsed();

	if (m_TimeCounter > m_TimePerDraw)
	{
		if (m_pTextComponent != nullptr)
		{
			std::string text{ "FPS: " + std::to_string(int(m_FrameCounter / m_TimePerDraw)) };
			m_pTextComponent->SetText(text);
		}
		else
		{
			std::cerr << "No text component assigned to fpsComponent\n";
		}
		
		m_FrameCounter = 0;
		m_TimeCounter -= m_TimePerDraw;
	}
	
}

void dae::FpsComponent::Render(const GameObject*) const
{
}
