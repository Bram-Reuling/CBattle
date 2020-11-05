#pragma once

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

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
	void HandleEvent(const sf::Event& event, sf::RenderWindow& window);
	void Update();
	void Render(sf::RenderWindow& window);
	std::string GetIdentifier() const;

	sf::Font font;
	sf::Color darkColor;
	sf::Color darkGreyColor;
	sf::Color lightGreyColor;
};
