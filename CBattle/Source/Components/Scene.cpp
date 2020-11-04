#include "Scene.hpp"

Scene::Scene(std::string identifier)
{
	this->identifier = identifier;
}

Scene::~Scene() = default;

void Scene::AddGameObject(GameObject object)
{
	this->listOfGameObjects.push_back(object);
}

void Scene::Update()
{
	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++)
	{
		this->listOfGameObjects[i].Update();
	}
}


void Scene::Render(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++)
	{
		this->listOfGameObjects[i].Update();
	}
}
