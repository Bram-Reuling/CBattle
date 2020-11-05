#pragma once

#include <map>
#include <stack>
#include "Scene.hpp"

class SceneHandler
{
private:
	std::map<std::string, Scene*> scenes;
	std::stack<Scene*> scenesStack;
public:
	SceneHandler();
	~SceneHandler();
public:
	void Render(sf::RenderWindow& window) const;
	void Update();

	void AddScene(Scene& scene);
	void StackScene(std::string sceneName);
	void PopScene();
};
