#include "CharacterSelection.hpp"
// TODO: Implement Randomize button and Play button.

CharacterSelection::CharacterSelection(std::string identifier, sf::RenderWindow& window, SceneHandler& handler) : Scene(std::move(identifier))
{
	Init(handler);
	InitBG();
	InitBackButton(window);
	InitRandomizeButton(window);
	InitPlayButton(window);

	InitStrengthButton(window);
	InitAgilityButton(window);
	InitWitsButton(window);

	std::string path = "Assets/SaveFiles/Characters";
	
}

CharacterSelection::~CharacterSelection()
{
	delete backButton;
	delete randomizeButton;
	delete playButton;
	delete strengthButton;
	delete agilityButton;
	delete witsButton;
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
	backButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f - 392.5f, 540.0f));

	backButton->SetButtonAction([this]()
	{
		this->handler->PopScene();
		this->handler->StackScene("MainMenu");
	});

	AddGameObject(*backButton);
}

void CharacterSelection::InitRandomizeButton(sf::RenderWindow& window)
{
	randomizeButton = new Button("randomizeButton", font, "RANDOMIZE", sf::Vector2f(192.5f, 50.0f), darkColor);
	randomizeButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f - 192.5f / 2.0f, 540.0f));

	randomizeButton->SetButtonAction([this]()
	{
		Strength = 0;
		Agility = 0;
		Wits = 0;
		PointsToSpend = TotalPoints;
		
		for (auto i = 0; i < TotalPoints; i++)
		{
			auto r = rand() % 3;
			if (r == 0)
			{
				strengthButton->OnClick();
			}
			else if (r == 1)
			{
				agilityButton->OnClick();
			}
			else
			{
				witsButton->OnClick();
			}
		}
	});

	AddGameObject(*randomizeButton);
}

void CharacterSelection::InitPlayButton(sf::RenderWindow& window)
{
	playButton = new Button("playButton", font, "PLAY", sf::Vector2f(192.5f, 50.0f), darkColor);
	playButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f + 192.5f, 540.0f));

	playButton->SetButtonAction([this]()
	{
		this->SavePlayer();
		this->handler->PopScene();
		this->handler->StackScene("FightScreen");
	});

	AddGameObject(*playButton);
}

void CharacterSelection::InitStrengthButton(sf::RenderWindow& window)
{
	strengthButton = new Button("strengthButton", font, std::to_string(Strength), sf::Vector2f(192.5f, 50.0f), darkColor);
	strengthButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f - 392.5f, 340.0f));

	strengthButton->SetButtonAction([this]()
	{
		if (PointsToSpend != 0)
		{
			++Strength;
			--PointsToSpend;

			strengthButton->UpdateText(std::to_string(Strength));
		}
	});

	AddGameObject(*strengthButton);
}

void CharacterSelection::InitAgilityButton(sf::RenderWindow& window)
{
	agilityButton = new Button("agilityButton", font, std::to_string(Agility), sf::Vector2f(192.5f, 50.0f), darkColor);
	agilityButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f - 192.5f / 2.0f, 340.0f));

	agilityButton->SetButtonAction([this]()
	{
		if (PointsToSpend != 0)
		{
			++Agility;
			--PointsToSpend;
			
			agilityButton->UpdateText(std::to_string(Agility));
		}
	});

	AddGameObject(*agilityButton);
}

void CharacterSelection::InitWitsButton(sf::RenderWindow& window)
{
	witsButton = new Button("witsButton", font, std::to_string(Wits), sf::Vector2f(192.5f, 50.0f), darkColor);
	witsButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f + 192.5f, 340.0f));

	witsButton->SetButtonAction([this]()
	{
		if (PointsToSpend != 0)
		{
			++Wits;
			--PointsToSpend;

			witsButton->UpdateText(std::to_string(Wits));
		}
	});

	AddGameObject(*witsButton);
}

void CharacterSelection::SceneIsActive()
{
	std::cout << "Char select is active!" << std::endl;
	
	std::ifstream playerPath("Assets/SaveFiles/Characters/Player.txt");
	std::string line;

	if (!playerPath.fail())
	{
		std::getline(playerPath, line);
		this->name = line;

		std::getline(playerPath, line);
		this->textureFile = line;

		std::getline(playerPath, line);
		this->HP = atoi(line.c_str());

		std::getline(playerPath, line);
		this->SP = atoi(line.c_str());

		std::getline(playerPath, line);
		this->Strength = atoi(line.c_str());

		std::getline(playerPath, line);
		this->Agility = atoi(line.c_str());

		std::getline(playerPath, line);
		this->Wits = atoi(line.c_str());

		std::getline(playerPath, line);
		this->PointsToSpend = atoi(line.c_str());

		std::getline(playerPath, line);
		this->TotalPoints = atoi(line.c_str());
	}

	playerPath.close();
	
	strengthButton->UpdateText(std::to_string(Strength));
	agilityButton->UpdateText(std::to_string(Agility));
	witsButton->UpdateText(std::to_string(Wits));
}

void CharacterSelection::SavePlayer()
{
	CalculateHealth();
	CalculateSanity();
	
	std::ofstream playerPath("Assets/SaveFiles/Characters/Player.txt");
	if (!playerPath.fail())
	{
		playerPath << this->name << "\n";
		playerPath << this->textureFile << "\n";
		playerPath << std::to_string(this->HP) << "\n";
		playerPath << std::to_string(this->SP) << "\n";
		playerPath << std::to_string(this->Strength) << "\n";
		playerPath << std::to_string(this->Agility) << "\n";
		playerPath << std::to_string(this->Wits) << "\n";
		playerPath << std::to_string(this->PointsToSpend) << "\n";
		playerPath << std::to_string(this->TotalPoints) << "\n";
	}

	playerPath.close();
}

void CharacterSelection::CalculateHealth()
{
	HP = 3 * Strength;
}

void CharacterSelection::CalculateSanity()
{
	SP = 2 * Wits;
}
