#include "MainMenu.hpp"

MainMenu::MainMenu(std::string identifier, sf::RenderWindow& window, SceneHandler& handler) : Scene(std::move(identifier))
{
	Init(handler);
	InitBG();
	InitQuitButton(window);
	InitBackButton(window);
}

MainMenu::~MainMenu()
{
	delete background;
	delete quitButton;
	delete background;
}

void MainMenu::Init(SceneHandler& handler)
{
	this->handler = &handler;
}

void MainMenu::InitBG()
{
	background = new SpriteObject("background", "Assets/Backgrounds/Battleground2.png");
	AddGameObject(*background);
}

void MainMenu::InitQuitButton(sf::RenderWindow& window)
{
	quitButton = new QuitButton("quitButton", font, "QUIT", sf::Vector2f(192.5f, 50.0f), darkColor, window);
	quitButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f - 192.5f / 2.0f, 540.0f));
	AddGameObject(*quitButton);
}

void MainMenu::InitBackButton(sf::RenderWindow& window)
{
	backButton = new Button("backButton", font, "BACK", sf::Vector2f(192.5f, 50.0f), darkColor);
	backButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f - 192.5f / 2.0f, 340.0f));

	backButton->SetButtonAction([this]()
	{
		this->handler->StackScene("StartScreen");
	});
	
	AddGameObject(*backButton);
}
