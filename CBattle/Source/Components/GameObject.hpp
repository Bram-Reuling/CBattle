#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class GameObject
{
private:
	// To easily identify the GameObject.
	const std::string identifier;
	
public:
	// Normal constructor, asks for identifier
	GameObject(std::string identifier);
	// Copy constructor, gets reference to other and copies identifier
	GameObject(const GameObject& other);

	// Overridable destructor
	virtual ~GameObject();
	
public:
	virtual void HandleEvent(const sf::Event& event, sf::RenderWindow& window) {};
	// Overridable Update function
	virtual void Update() = 0;
	// Overridable Render Function
	virtual  void Render(sf::RenderWindow& window) = 0;
	// Getter for identifier
	std::string GetIdentifier() const;
};
