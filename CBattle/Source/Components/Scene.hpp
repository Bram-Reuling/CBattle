#pragma once

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

class Scene
{
private:
	std::string identifier;
	
public:
	Scene(std::string identifier);
	~Scene();

public:
	void Update();
	void Render(sf::RenderWindow& window);
};
