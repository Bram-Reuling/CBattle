#include "MainMenu.hpp"

MainMenu::MainMenu(std::string identifier, sf::RenderWindow& window, SceneHandler& handler) : Scene(std::move(identifier))
{
	Init(handler);
	InitBG();
	InitQuitButton(window);
	InitBackButton(window);
}

MainMenu::~MainMenu()
{
	
}

void MainMenu::Init(SceneHandler& handler)
{
	
}

void MainMenu::InitBG()
{
	
}

void MainMenu::InitQuitButton(sf::RenderWindow& window)
{
	
}

void MainMenu::InitBackButton(sf::RenderWindow& window)
{
	
}
