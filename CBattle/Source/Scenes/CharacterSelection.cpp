#include "CharacterSelection.hpp"
// TODO: Implement Randomize button and Play button.

CharacterSelection::CharacterSelection(std::string identifier, sf::RenderWindow& window, SceneHandler& handler) : Scene(std::move(identifier))
{
	Init(handler);
	InitBG();
	InitBackButton(window);

	std::string path = "Assets/SaveFiles/Characters";
	
}

CharacterSelection::~CharacterSelection()
{
	delete backButton;
	delete randomizeButton;
	delete playButton;
}

void CharacterSelection::Init(SceneHandler& handler)
{
	this->handler = &handler;
}

void CharacterSelection::InitBG()
{
	Background("Assets/Backgrounds/Battleground3.png");
}

void CharacterSelection::InitBackButton(sf::RenderWindow& window)
{
	backButton = new Button("backButton", font, "BACK", sf::Vector2f(192.5f, 50.0f), darkColor);
	backButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f - 192.5f / 2.0f, 340.0f));

	backButton->SetButtonAction([this]()
	{
		this->handler->PopScene();
		this->handler->StackScene("MainMenu");
	});

	AddGameObject(*backButton);
}
