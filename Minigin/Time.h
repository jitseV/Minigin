#pragma once
#include "Singleton.h"


namespace dae
{
	class Time : public Singleton<Time>
	{
	public:
		Time();
		~Time() = default;

		void Update(float deltaTime);
		float GetElapsed() const;
		float GetAccumulated() const;

	private:
		float m_elapsed;
		float m_accumulated;
	};

}

