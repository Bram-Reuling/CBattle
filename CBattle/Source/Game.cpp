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

int main()
{
	// Setup of window
	sf::RenderWindow window(sf::VideoMode(1280, 720), "CBattle");

	Scene scene1("scene1");

	SpriteObject sprite1("soldierSprite", "Assets/head.png");
	sprite1.SetPosition(sf::Vector2f(70.0f, 70.0f));
	sprite1.SetScale(sf::Vector2f(5.0f, 5.0f));
	scene1.AddGameObject(sprite1);

	Scene scene2("scene2");

	SpriteObject sprite2("soldierSprite", "Assets/head_hurt.png");
	sprite2.SetPosition(sf::Vector2f(70.0f, 70.0f));
	sprite2.SetScale(sf::Vector2f(5.0f, 5.0f));
	scene2.AddGameObject(sprite2);

	SceneHandler handler;
	handler.AddScene(scene1);
	handler.AddScene(scene2);

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
					if (counter == 0)
					{
						handler.StackScene("scene2");
						counter++;
					}
					else
					{
						handler.PopScene();
						counter--;
					}
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