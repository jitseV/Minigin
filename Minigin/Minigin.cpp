#include "MiniginPCH.h"
#include "Minigin.h"
#include <chrono>
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include <SDL.h>
#include "GameObject.h"
#include "Scene.h"
#include "Time.h"

#include "RenderComponent.h"
#include "TextComponent.h"
#include "FpsComponent.h"

using namespace std;
using namespace std::chrono;

void dae::Minigin::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr)
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(m_Window);

	
}

/**
 * Code constructing the scene world starts here
 */
void dae::Minigin::LoadGame() const
{
	//TODO add loading from file support
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	//make background game object
	GameObject* backgroundGO = new GameObject();
	RenderComponent* pRc = new RenderComponent("background.jpg");
	backgroundGO->AddComponent(pRc);
	scene.Add(backgroundGO);

	//make logo game object
	GameObject* logoGO = new GameObject();
	RenderComponent* pRc2 = new RenderComponent("logo.png");
	logoGO->AddComponent(pRc2);
	logoGO->SetPosition(210.f, 250.f);
	scene.Add(logoGO);


	//make "Programming 4 Assignment" text
	GameObject* textGO{ new GameObject() };
	Component* pTextComp = new TextComponent("Programming 4 Assignment", "Data/Lingua.otf", 26);
	textGO->AddComponent(pTextComp);
	textGO->SetPosition(140.f, 120.f);
	scene.Add(textGO);

	//make fps game object
	GameObject* fpsGO{ new GameObject() };
	Component* pText = new TextComponent("FPS: ", "Data/Lingua.otf", 40);
	Component* pFPS = new FpsComponent(dynamic_cast<TextComponent*>(pText));
	fpsGO->AddComponent(pText);
	fpsGO->AddComponent(pFPS);
	scene.Add(fpsGO);
	
}

void dae::Minigin::Cleanup()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void dae::Minigin::Run()
{
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{ 

		auto& renderer = Renderer::GetInstance(); 
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();


		//game loop
		bool doContinue = true;
		auto previousTime = high_resolution_clock::now();
		while (doContinue)
		{
			const auto currentTime = high_resolution_clock::now();
			float deltaTime = duration<float>(currentTime - previousTime).count();
			Time::GetInstance().Update(deltaTime);
			
			doContinue = input.ProcessInput();
			sceneManager.Update(); //TODO delta time will come from Time Singleton 
			renderer.Render();

			previousTime = currentTime;
		}
	}

	Cleanup();
}
