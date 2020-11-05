#include "Button.hpp"

#include <SFML/Window/Event.hpp>

Button::Button(std::string identifier, sf::Font& font, std::string buttonText, sf::Vector2f size, sf::Color color) :
	GameObject(identifier), font(font), buttonText(buttonText)
{
	// Setting up the shape variable
	this->shape.setSize(size);
	this->shape.setFillColor(color);
	this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setOutlineThickness(1);

	// Setting up the text.
	this->text.setFont(font);
	this->text.setString(buttonText);
	this->text.setCharacterSize(26);
	this->text.setFillColor(sf::Color::White);

	// Getting the bounds of the text.
	sf::FloatRect textRect = this->text.getLocalBounds();
	// Setting the origin to the middle of the textRect
	this->text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

	// Setting the default position of the button.
	this->SetPosition(sf::Vector2f(0.0f, 0.0f));
}

Button::~Button()
{
	
}

void Button::HandleEvent(const sf::Event& event, sf::RenderWindow& window)
{
	// Checks if the left mouse button is pressed
	if (event.type == sf::Event::MouseButtonPressed &&
		event.mouseButton.button == sf::Mouse::Button::Left)
	{
		// If so, retrieve the position of the mouse,
		// the size of the button and the position of the button.
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		sf::Vector2f size = shape.getSize();
		sf::Vector2f position = shape.getPosition();

		// Checks if the mouse is in the bounds of the button.
		if (mousePosition.x >= position.x && mousePosition.x <= position.x + size.x &&
			mousePosition.y >= position.y && mousePosition.y <= position.y + size.y)
		{
			// If so, call the OnClick method.
			this->OnClick();
		}
	}
}

void Button::Update()
{
	
}

void Button::Render(sf::RenderWindow& window)
{
	window.draw(this->shape);
	window.draw(this->text);
}

void Button::SetCharacterSize(const int size)
{
	this->text.setCharacterSize(size);
}

void Button::SetPosition(const sf::Vector2f position)
{
	this->shape.setPosition(position);
	sf::Vector2f size = this->shape.getSize();
	sf::Vector2f centerButton(position.x + (size.x / 2.0f), position.y + (size.y / 2.0f));
	this->text.setPosition(centerButton);
}

void Button::OnClick()
{
	this->action();
}

void Button::SetButtonAction(std::function<void()> action)
{
	this->action = action;
}