#include "MiniginPCH.h"
#include "GameObject.h"
#include "Component.h"
#include "ResourceManager.h"


dae::GameObject::~GameObject() = default;

void dae::GameObject::Update()
{
	for(Component* pComponent: m_pComponents)
	{
		pComponent->Update(this);
	}
}

void dae::GameObject::Render() const
{
	for(Component* pComponent: m_pComponents)
	{
		pComponent->Render(this);
	}
}


void dae::GameObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}

const dae::Transform& dae::GameObject::GetTransform() const
{
	return m_Transform;
}

void dae::GameObject::AddComponent(Component* pComponent)
{
	m_pComponents.push_back(pComponent);
}
