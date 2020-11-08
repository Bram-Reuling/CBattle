#pragma once
#include "GameObject.hpp"

class Character : public GameObject
{
private:
	std::string const name;
	std::string const textureFile;

	int HealthPoints;
	int SanityPoints;

	int StrengthPoints;
	int AgilityPoints;
	int WitsPoints;
public:
	Character(const char* name, const char* textureFile, const int HP, const int SP, const int Strength, const int Agility, const int Wits);
	~Character();

	// Getters
	std::string GetName() const;
	std::string GetTextureFile() const;

	int GetHealthPoints() const;
	int GetSanityPoints() const;

	int GetStrengthPoints() const;
	int GetAgilityPoints() const;
	int GetWitsPoints() const;

	// Takers
	bool TakeHealth(const int& value);
	bool TakeSanity(const int& value);

	// Gainers
	bool GainHealth(const int& value);
	bool GainSanity(const int& value);

	bool GainStrength();
	bool GainAgility();
	bool GainWits();
};
