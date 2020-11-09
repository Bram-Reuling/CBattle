#pragma once
#include "../Components/Scene.hpp"
#include "../Components/SpriteObject.hpp"
#include "../Components/Button.hpp"
#include "../Components/QuitButton.hpp"
#include "../Components/SceneHandler.hpp"

///
/// Create function for Determining and Setting the turns.
/// At the beginning of this scene the determine function runs
/// At button press or turnDone Setting is called
/// 

class FightScreen : public Scene
{
public:
	FightScreen(std::string identifier, sf::RenderWindow& window, SceneHandler& handler);
	~FightScreen();

private:
	void Init(SceneHandler& handler);
	void InitBG();
	void InitBackButton(sf::RenderWindow& window);
	void InitAttackButton(sf::RenderWindow& window);
	void InitPrepareButton(sf::RenderWindow& window);
	void InitRecoverButton(sf::RenderWindow& window);
	void InitCastMagicButton(sf::RenderWindow& window);

	void SceneIsActive() override;

private:
	SceneHandler* handler;

	Button* backButton;
	Button* attackButton;
	Button* prepareButton;
	Button* recoverButton;
	Button* castMagicButton;
};
