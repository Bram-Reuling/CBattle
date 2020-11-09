///
/// Created by: Bram Reuling
/// 
/// Description:
/// This is the main file.
///

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "Components/Scene.hpp"
#include "Components/SpriteObject.hpp"
#include "Components/SceneHandler.hpp"
#include "Scenes/Scenes.hpp"

int main()
{
	std::ifstream iconPaths("Assets/SaveFiles/Characters/Player.txt");
	std::string line;
	if (!iconPaths.fail())
	{
		while(std::getline(iconPaths, line))
		{
			std::cout << line.c_str() << std::endl;
		}
	}
	iconPaths.close();
	
	// Setup of window
	sf::RenderWindow window(sf::VideoMode(1280, 720), "CBattle");
	SceneHandler handler;

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