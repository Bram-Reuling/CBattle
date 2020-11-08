#pragma once
#include "../Components/Scene.hpp"
#include "../Components/SpriteObject.hpp"
#include "../Components/Button.hpp"
#include "../Components/QuitButton.hpp"
#include "../Components/SceneHandler.hpp"
#include <fstream>

class CharacterSelection : public Scene
{
public:
	CharacterSelection(std::string identifier, sf::RenderWindow& window, SceneHandler& handler);
	~CharacterSelection();

private:
	void Init(SceneHandler& handler);
	void InitBG();
	void InitBackButton(sf::RenderWindow& window);
	void InitRandomizeButton(sf::RenderWindow& window);
	void InitPlayButton(sf::RenderWindow& window);

private:
	SceneHandler* handler;
	Button* backButton;

	Button* randomizeButton;
	Button* playButton;
};
