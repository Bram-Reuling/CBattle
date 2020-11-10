#pragma once
#include "../Components/Scene.hpp"
#include "../Components/SpriteObject.hpp"
#include "../Components/Button.hpp"
#include "../Components/QuitButton.hpp"
#include "../Components/SceneHandler.hpp"
#include <memory>

class MainMenu : public Scene
{
public:
	MainMenu(std::string identifier, sf::RenderWindow& window, SceneHandler& handler);
	~MainMenu() override;

private:
	void Init(SceneHandler& handler);
	void InitBG();
	void InitBackButton(sf::RenderWindow& window);
	void InitQuitButton(sf::RenderWindow& window);
	void InitPlayButton(sf::RenderWindow& window);
	void InitEraseDataButton(sf::RenderWindow& window);

	void SceneIsActive() override;

private:
	SceneHandler* handler{};

	std::unique_ptr<QuitButton> quitButton;

	std::unique_ptr<Button> playButton;
	std::unique_ptr<Button> backButton;
	std::unique_ptr<Button> eraseData;
};
