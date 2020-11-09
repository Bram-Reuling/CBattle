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
	std::cout << "Pushed Scene!" << std::endl;
	this->scenesStack.push(scenes[sceneName]);
	this->scenesStack.top()->SceneIsActive();
}

void SceneHandler::PopScene()
{
	std::cout << "Popped Scene!" << std::endl;
	this->scenesStack.pop();
}

std::string SceneHandler::GetSceneName()
{
	return this->scenesStack.top()->GetIdentifier();
}

void SceneHandler::HandleEvent(const sf::Event& event, sf::RenderWindow& window)
{
	this->scenesStack.top()->HandleEvent(event, window);
}
