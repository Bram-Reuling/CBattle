///
/// Created by: Bram Reuling
/// 
/// Description:
/// This is the main file.
///

#include <SFML/Graphics.hpp>
#include "Components/Scene.hpp"
#include "Components/SceneHandler.hpp"
#include "Scenes/Scenes.hpp"

int main()
{	
	// Setup of window
	sf::RenderWindow window(sf::VideoMode(1280, 720), "CBattle");
	SceneHandler handler;

	sf::Image icon;
	icon.loadFromFile("Assets/Characters/Player/Icons_01.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// Scenes setup
	StartScreen startScreen("StartScreen", window, handler);
	MainMenu mainMenu("MainMenu", window, handler);
	CharacterSelection characterSelection("CharacterSelection", window, handler);
	FightScreen fightScreen("FightScreen", window, handler);
	
	handler.AddScene(startScreen);
	handler.AddScene(mainMenu);
	handler.AddScene(characterSelection);
	handler.AddScene(fightScreen);

	auto counter = 0;
	// Check if the window is open.
	while (window.isOpen())
	{
		// Events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::EventType::Closed:
				window.close();
				break;
			default:
				handler.HandleEvent(event, window);
				break;
			}
		}
		window.clear();
		handler.Update();
		handler.Render(window);
		window.display();
	}
}