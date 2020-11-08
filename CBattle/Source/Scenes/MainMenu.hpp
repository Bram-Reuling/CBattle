#pragma once
#include "../Components/Scene.hpp"
#include "../Components/SpriteObject.hpp"
#include "../Components/Button.hpp"
#include "../Components/QuitButton.hpp"
#include "../Components/SceneHandler.hpp"

class MainMenu : public Scene
{
public:
	MainMenu(std::string identifier, sf::RenderWindow& window, SceneHandler& handler);
	~MainMenu();

private:
	void Init(SceneHandler& handler);
	void InitBG();
	void InitBackButton(sf::RenderWindow& window);
	void InitQuitButton(sf::RenderWindow& window);
	void InitPlayButton(sf::RenderWindow& window);
	void InitEraseDataButton(sf::RenderWindow& window);

private:
	SceneHandler* handler;

	QuitButton* quitButton;

	Button* playButton;
	Button* backButton;
	Button* eraseData;
};
