#pragma once
#include "WindowSystem/Window.h"
#include "EventSystem/EventManager.h"
#include "StateSystem/StateManager.h"
#include "Resources/TextureManager.h"
#include "Utilities/RandomNumberGen.h"
#include "Resources/FontManager.h"
#include "Resources/AudioManager.h"
#include "SoundSystem/SoundManager.h"
#include "MapSystem/Map.h"
#include "ECS/Core/System_Manager.h"
#include "ECS/Core/Entity_Manager.h"
#include "GUI/GUI_Manager.h"
#include "ParticleSystem/ParticleSystem.h"

class Game {
public:
	Game();
	~Game();

	void Update();
	void Render();
	void LateUpdate();

	sf::Time GetElapsed();

	Window* GetWindow();

private:
	void SetUpClasses();
	void SetUpECS();
	void SetUpStates();
	void RestartClock();
	sf::Clock m_clock;
	sf::Time m_elapsed;
	SharedContext m_context;
	RandomNumberGenerator m_rand;
	Window m_window;
	TextureManager m_textureManager;
	FontManager m_fontManager;
	AudioManager m_audioManager;
	SoundManager m_soundManager;
	GUI_Manager m_guiManager;
	SystemManager m_systemManager;
	EntityManager m_entityManager;
	Map m_gameMap;
	std::unique_ptr<ParticleSystem> m_particles;
	std::unique_ptr<StateManager> m_stateManager;
};