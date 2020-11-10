#pragma once
#include "../Components/Scene.hpp"
#include "../Components/SpriteObject.hpp"
#include "../Components/Button.hpp"
#include "../Components/QuitButton.hpp"
#include "../Components/TextObject.hpp"
#include "../Components/SceneHandler.hpp"
#include <fstream>
#include <memory>

class CharacterSelection : public Scene
{
public:
	CharacterSelection(std::string identifier, sf::RenderWindow& window, SceneHandler& handler);
	~CharacterSelection() override;

private:
	void Init(SceneHandler& handler_);
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
	
	std::unique_ptr<Button> backButton;
	std::unique_ptr<Button> randomizeButton;
	std::unique_ptr<Button> playButton;

	std::unique_ptr<Button> strengthButton;
	std::unique_ptr<Button> agilityButton;
	std::unique_ptr<Button> witsButton;

	std::unique_ptr<TextObject> strengthText;
	std::unique_ptr<TextObject> agilityText;
	std::unique_ptr<TextObject> witsText;

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
