///
/// Created by: Bram Reuling
/// 
/// Description:
/// This is the main file.
///

#include <SFML/Graphics.hpp>

#include "Components/Scene.hpp"
#include "Components/SpriteObject.hpp"
#include "Components/SceneHandler.hpp"
#include "Scenes/Scenes.hpp"

int main()
{
	// Setup of window
	sf::RenderWindow window(sf::VideoMode(1280, 720), "CBattle");

	StartScreen startScreen("StartScreen");

	SceneHandler handler;
	handler.AddScene(startScreen);

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
			case sf::Event::EventType::KeyReleased:
				if (event.key.code == sf::Keyboard::A)
				{

				}
				break;
			}
		}
		window.clear();
		handler.Update();
		handler.Render(window);
		window.display();
	}
}