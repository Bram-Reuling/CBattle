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
	void InitPlayButton(sf::RenderWindow& window);
	void InitQuitButton(sf::RenderWindow& window);
	
private:
	SceneHandler* handler;
	
	SpriteObject* background;
	QuitButton* quitButton;
	Button* playButton;
};
