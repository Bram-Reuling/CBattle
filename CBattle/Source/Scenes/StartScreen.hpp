#pragma once
#include "../Components/Scene.hpp"
#include "../Components/SpriteObject.hpp"
#include "../Components/Button.hpp"
#include "../Components/QuitButton.hpp"
#include "../Components/SceneHandler.hpp"

class StartScreen : public Scene
{	
public:
	StartScreen(std::string identifier, sf::RenderWindow& window, SceneHandler& handler);
	~StartScreen();

private:
	void Init(SceneHandler& handler);
	void InitBG();
	void InitStartButton(sf::RenderWindow& window);
	void InitQuitButton(sf::RenderWindow& window);

	void SceneIsActive() override;
	
private:
	SceneHandler* handler;
	
	QuitButton* quitButton;
	Button* startButton;
};
