#pragma once
#include "Transform.h"
#include <vector>
#include "Component.h"

namespace dae
{
	class GameObject final
	{
	public:
		void Update();
		void Render() const;

		void SetPosition(float x, float y);
		const Transform& GetTransform() const;

		void AddComponent(Component* pComponent);

		template<typename T>
		Component* GetComponent() const
		{
			for(Component* pComponent : m_pComponents)
			{
				if(dynamic_cast<Component*>(pComponent))
				{
					return pComponent;
				}
			}

			return nullptr;
		}
		

		GameObject() = default;
		~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_Transform;
		std::vector<Component*>	m_pComponents;
	};
}
