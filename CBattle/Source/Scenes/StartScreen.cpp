#include "StartScreen.hpp"

void StartScreen::InitStartButton(sf::RenderWindow& window)
{
	startButton = std::make_unique<Button>("startButton", font, "START", sf::Vector2f(192.5f, 50.0f), darkColor);
	startButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f - 192.5f / 2.0f, 440.0f));

	startButton->SetButtonAction([this]()
	{
		this->handler->PopScene();
		this->handler->StackScene("MainMenu");
	});
	
	AddGameObject(*startButton);
}

void StartScreen::Init(SceneHandler& handler_)
{
	this->handler = &handler_;
}

void StartScreen::InitBG()
{
	Background("Assets/Backgrounds/Battleground1.png");
}

void StartScreen::InitQuitButton(sf::RenderWindow& window)
{
	quitButton = std::make_unique<QuitButton>("quitButton", font, "QUIT", sf::Vector2f(192.5f, 50.0f), darkColor, window);
	quitButton->SetPosition(sf::Vector2f(window.getSize().x/2.0f - 192.5f/2.0f, 540.0f));
	AddGameObject(*quitButton);
}

StartScreen::StartScreen(std::string identifier, sf::RenderWindow& window, SceneHandler& handler) : Scene(std::move(identifier))
{
	Init(handler);
	
	InitBG();

	InitQuitButton(window);

	InitStartButton(window);
}

StartScreen::~StartScreen() = default;

void StartScreen::SceneIsActive()
{
	std::cout << "StartScreen is active!" << std::endl;
}
