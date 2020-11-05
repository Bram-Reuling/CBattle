#include "SceneHandler.hpp"

SceneHandler::SceneHandler()
{
	
}

SceneHandler::~SceneHandler()
{
	
}

void SceneHandler::Render(sf::RenderWindow& window) const
{
	if(!this->scenesStack.empty())
	{
		this->scenesStack.top()->Render(window);
	}
}

void SceneHandler::Update()
{
	if (!this->scenesStack.empty())
	{
		this->scenesStack.top()->Update();
	}
}

void SceneHandler::AddScene(Scene& scene)
{
	this->scenes.emplace(scene.GetIdentifier(), &scene);
	if(this->scenes.size() == 1)
	{
		this->StackScene(scene.GetIdentifier());
	}
}

void SceneHandler::StackScene(std::string sceneName)
{
	this->scenesStack.push(scenes[sceneName]);
}

void SceneHandler::PopScene()
{
	this->scenesStack.pop();
}
