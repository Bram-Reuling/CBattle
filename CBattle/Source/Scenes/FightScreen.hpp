#pragma once
#include "../Components/Scene.hpp"
#include "../Components/SpriteObject.hpp"
#include "../Components/Button.hpp"
#include "../Components/SceneHandler.hpp"
#include "../Components/Character.hpp"
#include "../Components/TextObject.hpp"

#include <fstream>
#include <ctime>
#include <memory>

class FightScreen : public Scene
{
public:
	FightScreen(std::string identifier, sf::RenderWindow& window, SceneHandler& handler_);
	~FightScreen() override;

private:
	void Init(SceneHandler& handler_);
	void InitBG();
	void InitBackButton(sf::RenderWindow& window);
	void InitAttackButton(sf::RenderWindow& window);
	//void InitPrepareButton(sf::RenderWindow& window);
	void InitRecoverButton(sf::RenderWindow& window);
	void InitCastMagicButton(sf::RenderWindow& window);

	void SceneIsActive() override;
	void InitPlayer();
	void InitOpponent();
	void DetermineStart();
	void DoAction(int AttackChance, int RecoverChance, int CastMagicChance, int sum, int r);

	void PickAction();

	void Attack(Character* attacker, Character* receiver);
	void Recover(Character* receiver);
	void CastMagic(Character* attacker, Character* receiver);

	void Delay();

private:
	SceneHandler* handler;
	bool playerTurn = false;

	std::unique_ptr<Button> backButton;
	std::unique_ptr<Button> attackButton;
	std::unique_ptr<Button> prepareButton;
	std::unique_ptr<Button> recoverButton;
	std::unique_ptr<Button> castMagicButton;
	
	Character* player;
	Character* opponent;

	std::unique_ptr<TextObject> playerHealth;
	std::unique_ptr<TextObject> opponentHealth;
	std::unique_ptr<TextObject> playerSanity;
	std::unique_ptr<TextObject> opponentSanity;

	std::unique_ptr<TextObject> playerActionText;
	std::unique_ptr<TextObject> opponentActionText;
};
