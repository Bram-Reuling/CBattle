#pragma once

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

#include "GameObject.hpp"

class Scene
{
private:
	const std::string identifier;
	// List of pointers to the GameObjects
	std::vector<GameObject*> listOfGameObjects;
	
public:
	Scene(std::string identifier);
	~Scene();

public:
	void AddGameObject(GameObject& object);
	void Update();
	void Render(sf::RenderWindow& window);
	std::string GetIdentifier() const;
};
