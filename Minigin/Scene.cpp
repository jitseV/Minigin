#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"

using namespace dae;

unsigned int Scene::m_IdCounter = 0;

Scene::Scene(const std::string& name) : m_Name(name) {}

Scene::~Scene() = default;

void Scene::Add(GameObject * object)
{
	m_pObjects.push_back(object);
}

void Scene::Update()
{
	for (GameObject* object : m_pObjects)
	{
		object->Update();
	}
}

void Scene::Render() const
{
	for (GameObject* object :m_pObjects)
	{
		object->Render();
	}
}

