#include "MiniginPCH.h"
#include "Time.h"

dae::Time::Time()
	:Singleton<Time>()
	, m_elapsed{}
	, m_accumulated{}
{
}

void dae::Time::Update(float deltaTime)
{
	m_elapsed = deltaTime;
	m_accumulated += deltaTime;
}

float dae::Time::GetElapsed() const
{
	return m_elapsed;
}

float dae::Time::GetAccumulated() const
{
	return m_accumulated;
}
