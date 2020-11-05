#include "TextObject.hpp"

TextObject::TextObject(std::string identifier, sf::Font& font, std::string textStr) : GameObject(identifier), font(font), textStr(textStr)
{
	this->text.setString(this->textStr);
	this->text.setPosition(this->position);
	this->text.setFont(this->font);
	this->text.setCharacterSize(12);
	this->text.setFillColor(sf::Color::Black);
}

TextObject::~TextObject()
{
	
}

void TextObject::Update()
{
	
}

void TextObject::Render(sf::RenderWindow& window)
{
	window.draw(this->text);
}

std::string TextObject::GetTextStr() const
{
	return this->textStr;
}

void TextObject::SetText(const std::string textStr)
{
	this->textStr = textStr;
	this->text.setString(this->textStr);
}

void TextObject::SetCharacterSize(const int size)
{
	this->text.setCharacterSize(size);
}

void TextObject::SetFillColor(const sf::Color color)
{
	this->text.setFillColor(color);
}

void TextObject::SetPosition(const sf::Vector2f position)
{
	this->text.setPosition(position);
}
