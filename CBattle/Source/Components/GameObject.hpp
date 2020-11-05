#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class GameObject
{
private:
	const std::string identifier;
	
public:
	GameObject(std::string identifier);
	GameObject(const GameObject& other);

	virtual ~GameObject();
	
public:
	virtual void Update() = 0;
	virtual  void Render(sf::RenderWindow& window) = 0;
	std::string GetIdentifier() const;
};
