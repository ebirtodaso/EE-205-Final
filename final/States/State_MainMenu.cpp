#include "State_MainMenu.h"
#include "../StateSystem/StateManager.h"
#include "../WindowSystem/Window.h"
#include "../GUI/GUI_Manager.h"
#include "../MapSystem/MapDefinitions.h"
#include "load.h"

State_MainMenu::State_MainMenu(StateManager* l_stateManager)
	: BaseState(l_stateManager) {}

State_MainMenu::~State_MainMenu() {}

void State_MainMenu::OnCreate() {
	auto context = m_stateMgr->GetContext();
	GUI_Manager* gui = context->m_guiManager;
	gui->LoadInterface("MainMenu.interface", "MainMenu");
	gui->GetInterface("MainMenu")->SetPosition(sf::Vector2f(250.f, 168.f));
	EventManager* eMgr = context->m_eventManager;
	eMgr->AddCallback("MainMenu_Play", &State_MainMenu::Play, this);
	eMgr->AddCallback("MainMenu_Quit", &State_MainMenu::Quit, this);
}

void State_MainMenu::OnDestroy() {
	m_stateMgr->GetContext()->m_guiManager->RemoveInterface(StateType::Game, "MainMenu");
	EventManager* eMgr = m_stateMgr->GetContext()->m_eventManager;
	eMgr->RemoveCallback(StateType::MainMenu, "MainMenu_Play");
	eMgr->RemoveCallback(StateType::MainMenu, "MainMenu_Quit");
}

void State_MainMenu::Activate() {
	auto& play = *m_stateMgr->GetContext()->m_guiManager->GetInterface("MainMenu")->GetElement("Play");
	if (m_stateMgr->HasState(StateType::Game)) { play.SetText("Resume"); }
	else { play.SetText("Play"); }
}

void State_MainMenu::Play(EventDetails* l_details) { m_stateMgr->SwitchTo(StateType::Game); }

void State_MainMenu::Quit(EventDetails* l_details) { m_stateMgr->GetContext()->m_wind->Close(); }