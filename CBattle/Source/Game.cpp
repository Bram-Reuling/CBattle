///
/// Created by: Bram Reuling
/// 
/// Description:
/// This is the main file.
///

#include <SFML/Graphics.hpp>

int main()
{
	// Setup of window
	sf::RenderWindow window(sf::VideoMode(1280, 720), "CBattle");

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
			}
		}
	}
}