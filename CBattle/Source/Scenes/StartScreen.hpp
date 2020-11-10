#pragma once
#include "../Components/Scene.hpp"
#include "../Components/SpriteObject.hpp"
#include "../Components/Button.hpp"
#include "../Components/QuitButton.hpp"
#include "../Components/SceneHandler.hpp"
#include <memory>

class StartScreen : public Scene
{	
public:
	StartScreen(std::string identifier, sf::RenderWindow& window, SceneHandler& handler);
	~StartScreen() override;

private:
	void Init(SceneHandler& handler_);
	void InitBG();
	void InitStartButton(sf::RenderWindow& window);
	void InitQuitButton(sf::RenderWindow& window);

	void SceneIsActive() override;
	
private:
	SceneHandler* handler;
	
	std::unique_ptr<QuitButton> quitButton;
	std::unique_ptr<Button> startButton;
};
