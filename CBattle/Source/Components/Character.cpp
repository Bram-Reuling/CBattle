#include "Character.hpp"

#pragma region Class Things

/// <summary>
/// Constructor.
/// </summary>
/// <param name="name"></param>
/// <param name="textureFile"></param>
/// <param name="HP"></param>
/// <param name="SP"></param>
/// <param name="Strength"></param>
/// <param name="Agility"></param>
/// <param name="Wits"></param>
Character::Character(const char* name, const char* textureFile, const int HP, const int SP, const int Strength, const int Agility, const int Wits) :
	SpriteObject(name, textureFile), name(name), textureFile(textureFile), HealthPoints(HP), SanityPoints(SP), StrengthPoints(Strength), AgilityPoints(Agility),
	WitsPoints(Wits)
{

}

/// <summary>
/// Destructor
/// </summary>
Character::~Character()
{

}

void Character::Render(sf::RenderWindow& window)
{
	
}

void Character::Update()
{
	
}

#pragma endregion

#pragma region Getters

/// <summary>
/// Gets the name of the character.
/// </summary>
/// <returns>The name of the character</returns>
std::string Character::GetName() const
{
	return this->name;
}

/// <summary>
/// Gets the path to the texture file of the character
/// </summary>
/// <returns>The path to the texture of the character</returns>
std::string Character::GetTextureFile() const
{
	return this->textureFile;
}

/// <summary>
/// Gets the number of Health Points of the character
/// </summary>
/// <returns>The current number of HP</returns>
int Character::GetHealthPoints() const
{
	return this->HealthPoints;
}

/// <summary>
/// Gets the number of Sanity Points of the character
/// </summary>
/// <returns>The current number of SP</returns>
int Character::GetSanityPoints() const
{
	return this->SanityPoints;
}

/// <summary>
/// Gets the number of Strength Points of the character
/// </summary>
/// <returns>The current number of Strength</returns>
int Character::GetStrengthPoints() const
{
	return this->StrengthPoints;
}

/// <summary>
/// Gets the number of Agility Points of the character
/// </summary>
/// <returns>The current number of Agility</returns>
int Character::GetAgilityPoints() const
{
	return this->AgilityPoints;
}

/// <summary>
/// Gets the number of Wits Points of the character
/// </summary>
/// <returns>The current number of Wits</returns>
int Character::GetWitsPoints() const
{
	return this->WitsPoints;
}

#pragma endregion

#pragma region Takers

/// <summary>
/// Takes a certain value from the current health.
/// (Deals damage)
/// </summary>
/// <param name="value">Number of HP to subtract</param>
/// <returns>True (operation successful)</returns>
bool Character::TakeHealth(const int& value)
{
	HealthPoints -= value;

	// Operation is successful
	return true;
}

/// <summary>
/// Takes a certain value from the current Sanity.
/// </summary>
/// <param name="value">Number of Sanity Points to subtract</param>
/// <returns>True (operation successful)</returns>
bool Character::TakeSanity(const int& value)
{
	SanityPoints -= value;

	// Operation is successful
	return true;
}

#pragma endregion

#pragma region Gainers

/// <summary>
/// Gains a certain amount of Health
/// </summary>
/// <param name="value">The amount of Health Points to gain.</param>
/// <returns>True (operation successful)</returns>
bool Character::GainHealth(const int& value)
{
	HealthPoints += value;
	
	// Operation is successful
	return true;
}

/// <summary>
/// Gains a certain amount of Sanity
/// </summary>
/// <param name="value">The amount of Sanity Points to gain.</param>
/// <returns>True (operation successful)</returns>
bool Character::GainSanity(const int& value)
{
	SanityPoints += value;
	
	// Operation is successful
	return true;
}

/// <summary>
/// Gains one Strength Point.
/// </summary>
/// <returns>True (operation successful)</returns>
bool Character::GainStrength()
{
	++StrengthPoints;
	// Operation is successful
	return true;
}

/// <summary>
/// Gains one Agility Point.
/// </summary>
/// <returns>True (operation successful)</returns>
bool Character::GainAgility()
{
	++AgilityPoints;
	// Operation is successful
	return true;
}

/// <summary>
/// Gains one Wits Point.
/// </summary>
/// <returns>True (operation successful)</returns>
bool Character::GainWits()
{
	++WitsPoints;
	// Operation is successful
	return true;
}

#pragma endregion 