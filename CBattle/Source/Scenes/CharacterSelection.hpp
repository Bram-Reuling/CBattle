#pragma once
#include "../Components/Scene.hpp"
#include "../Components/SpriteObject.hpp"
#include "../Components/Button.hpp"
#include "../Components/QuitButton.hpp"
#include "../Components/TextObject.hpp"
#include "../Components/SceneHandler.hpp"
#include <fstream>
#include <sstream>

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
	void InitStrengthButton(sf::RenderWindow& window);
	void InitAgilityButton(sf::RenderWindow& window);
	void InitWitsButton(sf::RenderWindow& window);

	void CalculateHealth();
	void CalculateSanity();
	
	void SceneIsActive() override;

	void SavePlayer();

	SceneHandler* handler;
	Button* backButton;

	Button* randomizeButton;
	Button* playButton;

	Button* strengthButton;
	Button* agilityButton;
	Button* witsButton;

	TextObject* strengthText;
	TextObject* agilityText;
	TextObject* witsText;

	// Character
	std::string name;
	std::string textureFile;

	int HP;
	int SP;
	int Strength;
	int Agility;
	int Wits;
	int PointsToSpend;
	int TotalPoints;
};
