#include "MainMenu.hpp"
// TODO: Implement eraseDataButton.

MainMenu::MainMenu(std::string identifier, sf::RenderWindow& window, SceneHandler& handler) : Scene(std::move(identifier))
{
	Init(handler);
	InitBG();
	InitQuitButton(window);
	InitPlayButton(window);
	InitEraseDataButton(window);
}

MainMenu::~MainMenu() =  default;

void MainMenu::Init(SceneHandler& handler_)
{
	this->handler = &handler_;
}

void MainMenu::InitBG()
{
	Background("Assets/Backgrounds/Battleground2.png");
}

void MainMenu::InitQuitButton(sf::RenderWindow& window)
{
	quitButton = std::make_unique<QuitButton>("quitButton", font, "QUIT", sf::Vector2f(192.5f, 50.0f), darkColor, window);
	quitButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f - 392.5f, 540.0f));
	AddGameObject(*quitButton);
}

void MainMenu::InitBackButton(sf::RenderWindow& window)
{
	backButton = std::make_unique<Button>("backButton", font, "BACK", sf::Vector2f(192.5f, 50.0f), darkColor);
	backButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f - 392.5f, 540.0f));

	backButton->SetButtonAction([this]()
	{
		this->handler->PopScene();
		this->handler->StackScene("StartScreen");
	});
	
	AddGameObject(*backButton);
}

void MainMenu::InitPlayButton(sf::RenderWindow& window)
{
	playButton = std::make_unique<Button>("playButton", font, "PLAY", sf::Vector2f(192.5f, 50.0f), darkColor);
	playButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f + 192.5f, 540.0f));

	playButton->SetButtonAction([this]()
	{
		this->handler->PopScene();
		this->handler->StackScene("CharacterSelection");
	});

	AddGameObject(*playButton);
}

void MainMenu::InitEraseDataButton(sf::RenderWindow& window)
{
	eraseData = std::make_unique<Button>("eraseData", font, "ERASE DATA", sf::Vector2f(192.5f, 50.0f), darkColor);
	eraseData->SetPosition(sf::Vector2f(window.getSize().x / 2.0f - 192.5f / 2.0f, 540.0f));

	eraseData->SetButtonAction([this]()
	{
		std::cout << "Erase Data" << std::endl;
	});

	AddGameObject(*eraseData);
}

void MainMenu::SceneIsActive()
{
	std::cout << "Main Menu is active!" << std::endl;
}
