#include "Scene.hpp"

Scene::Scene(std::string identifier) : identifier(identifier)
{
	
}

Scene::~Scene()
{
	
}

void Scene::AddGameObject(GameObject &object)
{
	this->listOfGameObjects.push_back(&object);
}

void Scene::HandleEvent(const sf::Event& event, sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++)
	{
		this->listOfGameObjects[i]->HandleEvent(event, window);
	}
}


void Scene::Update()
{
	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++)
	{
		this->listOfGameObjects[i]->Update();
	}
}

void Scene::Render(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < this->listOfGameObjects.size(); i++)
	{
		this->listOfGameObjects[i]->Render(window);
	}
}

std::string Scene::GetIdentifier() const
{
	return this->identifier;
}
