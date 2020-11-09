#pragma once

#include "GameObject.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <functional>

class Button : public GameObject
{
private:
	sf::Text text;
	sf::Font& font;
	sf::RectangleShape shape;
	std::string buttonText;

	std::function<void()> action;
	
public:
	Button(std::string identifier, sf::Font& font, std::string buttonText,
		sf::Vector2f size, sf::Color color);
	~Button();

	void HandleEvent(const sf::Event& event, sf::RenderWindow& window) override;
	virtual void OnClick();
	
	void Update() override;
	void Render(sf::RenderWindow& window) override;

	void SetButtonAction(std::function<void()> action);
	void SetCharacterSize(const int size);
	void SetPosition(const sf::Vector2f position);

	void UpdateText(std::string value);
};
