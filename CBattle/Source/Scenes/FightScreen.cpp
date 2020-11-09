#include "FightScreen.hpp"
// TODO: Implement Attack, Prepare, Recover, Cast Magic buttons.

FightScreen::FightScreen(std::string identifier, sf::RenderWindow& window, SceneHandler& handler) : Scene(std::move(identifier))
{
	Init(handler);
	InitBG();
	InitBackButton(window);
}

FightScreen::~FightScreen()
{
	delete backButton;
}

void FightScreen::Init(SceneHandler& handler)
{
	this->handler = &handler;
}

void FightScreen::InitBG()
{
	Background("Assets/Backgrounds/Battleground4.png");
}

void FightScreen::InitBackButton(sf::RenderWindow& window)
{
	backButton = new Button("backButton", font, "BACK", sf::Vector2f(192.5f, 50.0f), darkColor);
	backButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f - 192.5f / 2.0f, 340.0f));

	backButton->SetButtonAction([this]()
	{
		this->handler->StackScene("MainMenu");
	});

	AddGameObject(*backButton);
}
void FightScreen::SceneIsActive()
{
	std::cout << "Fight scene is active!" << std::endl;
}
