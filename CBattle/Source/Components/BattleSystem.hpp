#pragma once
#include "Character.hpp"

class BattleSystem
{
private:
	
public:
	Character* player;
	Character* opponent;

	BattleSystem(const Character& player);
	~BattleSystem();

	void CreateRandomOpponent();
	void DetermineStart();
	void SetTurn();

	void PickAction();
	
	void Attack();
	void Prepare();
	void Recover();
	void CastMagic();
	void TrembleInFear();
};
