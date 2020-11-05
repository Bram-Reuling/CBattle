#include "StartScreen.hpp"

#include <utility>

StartScreen::StartScreen(std::string identifier) : Scene(std::move(identifier))
{
	// Initialize background
	background = new SpriteObject("background", "Assets/Backgrounds/Battleground1.png");
	AddGameObject(*background);
}

StartScreen::~StartScreen()
{
	delete background;
}
