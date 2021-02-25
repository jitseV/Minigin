#pragma once

namespace dae
{
	class GameObject;
	class Component
	{
	public:

		Component() = default;
		virtual ~Component() = default;
		virtual void Update(GameObject* gameObject) = 0;
		virtual void Render(const GameObject* gameObject) const = 0;


	private:


	};


}
