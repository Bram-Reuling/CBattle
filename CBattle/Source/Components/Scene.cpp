#include "Scene.hpp"

#include <iostream>
#include <utility>

Scene::Scene(std::string identifier) : identifier(std::move(identifier))
{
	font.loadFromFile("Assets/Fonts/Lato-Regular.ttf");
	darkColor = sf::Color(71, 82, 94, 255);
	darkGreyColor = sf::Color(132, 146, 166, 255);
	lightGreyColor = sf::Color(129, 144, 165, 255);
}

Scene::~Scene() = default;

/// <summary>
/// Ads a GameObject to the GameObjects vector
/// </summary>
/// <param name="object">A GameObject</param>
void Scene::AddGameObject(GameObject &object)
{
	this->listOfGameObjects.push_back(&object);
}

/// <summary>
/// Handles the events of the GameObjects
/// </summary>
/// <param name="event"></param>
/// <param name="window"></param>
void Scene::HandleEvent(const sf::Event& event, sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++)
	{
		this->listOfGameObjects[i]->HandleEvent(event, window);
	}
}

/// <summary>
/// Updates the GameObjects
/// </summary>
void Scene::Update()
{
	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++)
	{
		this->listOfGameObjects[i]->Update();
	}
}

/// <summary>
/// Renders the GameObjects to the screen
/// </summary>
/// <param name="window"></param>
void Scene::Render(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++)
	{
		this->listOfGameObjects[i]->Render(window);
	}
}

/// <summary>
/// Gets the Identifier of this scene
/// </summary>
/// <returns></returns>
std::string Scene::GetIdentifier() const
{
	return this->identifier;
}

/// <summary>
/// Sets the Background of the scene
/// </summary>
/// <param name="spriteFile"></param>
void Scene::Background(std::string spriteFile)
{
	background = new SpriteObject("background", std::move(spriteFile));
	AddGameObject(*background);
}

void Scene::SceneIsActive()
{
	
}
