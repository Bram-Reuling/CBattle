#include "StartScreen.hpp"

void StartScreen::InitPlayButton(sf::RenderWindow& window)
{
	playButton = new Button("playButton", font, "PLAY", sf::Vector2f(192.5f, 50.0f), darkColor);
	playButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f - 192.5f / 2.0f, 440.0f));

	playButton->SetButtonAction([this]()
	{
		this->handler->StackScene("Test");
	});
	
	AddGameObject(*playButton);
}

void StartScreen::Init(SceneHandler& handler)
{
	this->handler = &handler;
}

void StartScreen::InitBG()
{
	// Initialize background
	background = new SpriteObject("background", "Assets/Backgrounds/Battleground1.png");
	AddGameObject(*background);
}

void StartScreen::InitQuitButton(sf::RenderWindow& window)
{
	quitButton = new QuitButton("quitButton", font, "QUIT", sf::Vector2f(192.5f, 50.0f), darkColor, window);
	quitButton->SetPosition(sf::Vector2f(window.getSize().x/2.0f - 192.5f/2.0f, 540.0f));
	AddGameObject(*quitButton);
}

StartScreen::StartScreen(std::string identifier, sf::RenderWindow& window, SceneHandler& handler) : Scene(std::move(identifier))
{
	Init(handler);
	
	InitBG();

	InitQuitButton(window);

	InitPlayButton(window);
}

StartScreen::~StartScreen()
{
	delete background;
	delete quitButton;
	delete background;
}
