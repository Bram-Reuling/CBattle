#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class GameObject
{
private:
	std::string identifier;
	
public:
	GameObject(std::string identifier);
	GameObject(const GameObject& other)
	{
		this->identifier = other.GetIdentifier();
	}
	~GameObject();
	
public:
	void Update();
	void Render(sf::RenderWindow& window);
	std::string GetIdentifier() const
	{
		return this->identifier;
	}
};
