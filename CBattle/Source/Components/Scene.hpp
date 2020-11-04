#pragma once

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

#include "GameObject.hpp"

class Scene
{
private:
	std::string identifier;
	std::vector<GameObject> listOfGameObjects;
	
public:
	Scene(std::string identifier);
	~Scene();

public:
	void AddGameObject(GameObject object);
	void Update();
	void Render(sf::RenderWindow& window);
};
