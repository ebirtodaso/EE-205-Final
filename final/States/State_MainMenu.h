#pragma once
#include "../StateSystem/BaseState.h"
#include "../EventSystem/EventManager.h"
#include "../ThreadWorkers/FileLoader.h"

using LoaderContainer = std::vector<FileLoader*>;

class State_MainMenu : public BaseState {
public:
	State_MainMenu(StateManager* l_stateManager);
	~State_MainMenu();

	void OnCreate();
	void OnDestroy();

	void Activate();

	void Play(EventDetails* l_details);
	void Quit(EventDetails* l_details);

private:

};