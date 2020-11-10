#pragma once

#include "GameObject.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class SpriteObject : public GameObject
{
private:
	
public:
	std::string spriteFile;
	sf::Sprite sprite;
	sf::Texture texture;
	SpriteObject(std::string identifier, std::string spriteFile);
	SpriteObject(const SpriteObject& other);
	~SpriteObject() override;

public:
	void Update() override;
	void Render(sf::RenderWindow& window) override;

	void SetPosition(sf::Vector2f position);
	void SetScale(sf::Vector2f scale);
	std::string GetSpriteFile() const;
};
