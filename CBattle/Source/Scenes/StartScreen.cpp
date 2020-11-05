#include "StartScreen.hpp"

StartScreen::StartScreen(std::string identifier) : Scene(identifier)
{
	// Initialize background
	background = new SpriteObject("background", "Assets/Backgrounds/Battleground1.png");
	AddGameObject(*background);

	
}

StartScreen::~StartScreen()
{
	delete background;
}
