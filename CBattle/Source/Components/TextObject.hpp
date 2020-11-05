#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "GameObject.hpp"

class TextObject : public GameObject
{
private:
	sf::Font& font;
	sf::Text text;
	std::string textStr;
	sf::Vector2f position;
	
public:
	TextObject(std::string identifier, sf::Font& font, std::string textStr);
	~TextObject();

	void Update() override;
	void Render(sf::RenderWindow& window) override;

	std::string GetTextStr() const;
	void SetText(const std::string textStr);
	void SetCharacterSize(const int size);
	void SetFillColor(const sf::Color color);
	void SetPosition(const sf::Vector2f position);
};
