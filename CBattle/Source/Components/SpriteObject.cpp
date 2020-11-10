#include "SpriteObject.hpp"

#include <iostream>

SpriteObject::SpriteObject(std::string identifier, std::string spriteFile) : GameObject(identifier), spriteFile(spriteFile)
{
	this->texture.loadFromFile(this->spriteFile);
	this->sprite.setTexture(this->texture);
}

SpriteObject::SpriteObject(const SpriteObject& other) : GameObject(other.GetIdentifier()), spriteFile(other.GetSpriteFile())
{
	this->texture.loadFromFile(this->spriteFile);
	this->sprite.setTexture(this->texture);
}

SpriteObject::~SpriteObject()
{
	
}

void SpriteObject::Update()
{
	
}

void SpriteObject::Render(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}

void SpriteObject::SetPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void SpriteObject::SetScale(sf::Vector2f scale)
{
	sprite.setScale(scale);
}

std::string SpriteObject::GetSpriteFile() const
{
	return this->spriteFile;
}

