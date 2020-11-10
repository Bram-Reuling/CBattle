#include "FightScreen.hpp"
// TODO: Implement Attack, Prepare, Recover, Cast Magic buttons.

FightScreen::FightScreen(std::string identifier, sf::RenderWindow& window, SceneHandler& handler_) : Scene(std::move(identifier))
{
	InitBG();
	Init(handler_);
	InitBackButton(window);
	InitAttackButton(window);
	InitRecoverButton(window);
	InitCastMagicButton(window);
}

FightScreen::~FightScreen()
{
	delete player;
	delete opponent;
}

void FightScreen::Init(SceneHandler& handler_)
{
	this->handler = &handler_;
	playerHealth = std::make_unique<TextObject>("playerHealth", font, "Player Health");
	opponentHealth = std::make_unique<TextObject>("opponentHealth", font, "Player Health");
	playerSanity = std::make_unique<TextObject>("playerSanity", font, "Player Health");
	opponentSanity = std::make_unique<TextObject>("opponentSanity", font, "Player Health");

	playerActionText = std::make_unique<TextObject>("playerActionText", font, "");
	opponentActionText = std::make_unique<TextObject>("opponentActionText", font, "");
	
	playerHealth->SetPosition(sf::Vector2f(200, 200));
	playerHealth->SetCharacterSize(25);
	playerHealth->SetFillColor(sf::Color::White);
	opponentHealth->SetPosition(sf::Vector2f(600, 200));
	opponentHealth->SetCharacterSize(25);
	opponentHealth->SetFillColor(sf::Color::White);
	playerSanity->SetPosition(sf::Vector2f(200, 250));
	playerSanity->SetCharacterSize(25);
	playerSanity->SetFillColor(sf::Color::White);
	opponentSanity->SetPosition(sf::Vector2f(600, 250));
	opponentSanity->SetCharacterSize(25);
	opponentSanity->SetFillColor(sf::Color::White);

	playerActionText->SetPosition(sf::Vector2f(200, 300));
	playerActionText->SetCharacterSize(25);
	playerActionText->SetFillColor(sf::Color::White);

	opponentActionText->SetPosition(sf::Vector2f(200, 350));
	opponentActionText->SetCharacterSize(25);
	opponentActionText->SetFillColor(sf::Color::White);
	
	AddGameObject(*playerHealth);
	AddGameObject(*opponentHealth);
	AddGameObject(*playerSanity);
	AddGameObject(*opponentSanity);

	AddGameObject(*playerActionText);
	AddGameObject(*opponentActionText);
}

void FightScreen::InitBG()
{
	Background("");
}

void FightScreen::InitBackButton(sf::RenderWindow& window)
{
	backButton = std::make_unique<Button>("backButton", font, "BACK", sf::Vector2f(192.5f, 50.0f), darkColor);
	backButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f - 192.5f / 2.0f, 540.0f));

	backButton->SetButtonAction([this]()
	{
		this->handler->StackScene("MainMenu");
	});

	AddGameObject(*backButton);
}

void FightScreen::InitAttackButton(sf::RenderWindow& window)
{
	attackButton = std::make_unique<Button>("attackButton", font, "ATTACK", sf::Vector2f(192.5f, 50.0f), darkColor);
	attackButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f - 392.5f, 440.0f));

	attackButton->SetButtonAction([this]()
	{
		if (playerTurn)
		{
			Attack(player,opponent);
			opponentHealth->SetText("Opponent Health: " + std::to_string(opponent->GetHealthPoints()));
		}
		else
		{
			Attack(opponent,player);
			playerHealth->SetText("Player Health: " + std::to_string(player->GetHealthPoints()));
		}
	});

	AddGameObject(*attackButton);
}

void FightScreen::InitRecoverButton(sf::RenderWindow& window)
{
	recoverButton = std::make_unique<Button>("recoverButton", font, "RECOVER", sf::Vector2f(192.5f, 50.0f), darkColor);
	recoverButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f - 192.5f / 2.0f, 440.0f));

	recoverButton->SetButtonAction([this]()
	{
		if (playerTurn)
		{
			Recover(player);
			playerHealth->SetText("Player Health: " + std::to_string(player->GetHealthPoints()));
		}
		else
		{
			Recover(opponent);
			opponentHealth->SetText("Opponent Health: " + std::to_string(opponent->GetHealthPoints()));
		}
	});

	AddGameObject(*recoverButton);
}

void FightScreen::InitCastMagicButton(sf::RenderWindow& window)
{
	castMagicButton = std::make_unique<Button>("castMagicButton", font, "CAST MAGIC", sf::Vector2f(192.5f, 50.0f), darkColor);
	castMagicButton->SetPosition(sf::Vector2f(window.getSize().x / 2.0f + 192.5f, 440.0f));

	castMagicButton->SetButtonAction([this]()
	{
		if (playerTurn)
		{
			CastMagic(player,opponent);
			opponentHealth->SetText("Opponent Health: " + std::to_string(opponent->GetHealthPoints()));
		}
		else
		{
			CastMagic(opponent,player);
			playerHealth->SetText("Player Health: " + std::to_string(player->GetHealthPoints()));
		}
	});

	AddGameObject(*castMagicButton);
}

void FightScreen::SceneIsActive()
{
	std::cout << "Fight scene is active!" << std::endl;
	// Sets up the player character
	InitPlayer();
	// Sets up the opponent character
	InitOpponent();

	// Determines who starts
	DetermineStart();

	if (!playerTurn)
	{
		PickAction();
	}
}

void FightScreen::InitPlayer()
{
	std::ifstream playerPath("Assets/SaveFiles/Characters/Player.cmgt");
	std::string line;

	if (!playerPath.fail())
	{
		std::getline(playerPath, line);
		auto name = line;

		std::getline(playerPath, line);
		auto textureFile = line;

		std::getline(playerPath, line);
		auto HP = atoi(line.c_str());

		std::getline(playerPath, line);
		auto SP = atoi(line.c_str());

		std::getline(playerPath, line);
		auto Strength = atoi(line.c_str());

		std::getline(playerPath, line);
		auto Agility = atoi(line.c_str());

		std::getline(playerPath, line);
		auto Wits = atoi(line.c_str());

		std::getline(playerPath, line);
		auto PointsToSpend = atoi(line.c_str());

		std::getline(playerPath, line);
		auto TotalPoints = atoi(line.c_str());

		player = new Character(name, textureFile, HP, SP, Strength, Agility, Wits);

		std::cout << "Successfully created the player with the following properties:" << std::endl <<
			"HP: " + std::to_string(player->GetHealthPoints()) << std::endl << "SP: " + std::to_string(player->GetSanityPoints()) << std::endl <<
			"Strength: " + std::to_string(player->GetStrengthPoints()) << std::endl << "Agility: " + std::to_string(player->GetAgilityPoints()) << std::endl <<
			"Wits: " + std::to_string(player->GetWitsPoints()) << std::endl;

		playerHealth->SetText("Player Health: " + std::to_string(player->GetHealthPoints()));
		playerSanity->SetText("Player Sanity: " + std::to_string(player->GetSanityPoints()));
	}

	player->SetPosition(sf::Vector2f(270.0f, 125.0f));
	player->SetScale(sf::Vector2f(2.0f, 2.0f));
	AddGameObject(*player);
	
	playerPath.close();
}

void FightScreen::InitOpponent()
{
	auto Strength = 1;
	auto Agility = 0;
	auto Wits = 1;
	auto PointsToSpend = 4;
	const auto TotalPoints = PointsToSpend;

	for (auto i = 0; i < TotalPoints; i++)
	{
		auto r = rand() % 3;
		if (r == 0)
		{
			++Strength;
			--PointsToSpend;
		}
		else if (r == 1)
		{
			++Agility;
			--PointsToSpend;
		}
		else
		{
			++Wits;
			--PointsToSpend;
		}
	}

	auto HP = 15 * Strength;
	auto SP = 9 * Wits;

	opponent = new Character("Noob2", "Assets/Characters/Player/Icons_02.png", HP, SP, Strength, Agility, Wits);

	std::cout << "Successfully created the opponent with the following properties:" << std::endl <<
		"HP: " + std::to_string(opponent->GetHealthPoints()) << std::endl << "SP: " + std::to_string(opponent->GetSanityPoints()) << std::endl <<
		"Strength: " + std::to_string(opponent->GetStrengthPoints()) << std::endl << "Agility: " + std::to_string(opponent->GetAgilityPoints()) << std::endl <<
		"Wits: " + std::to_string(opponent->GetWitsPoints()) << std::endl;

	opponentHealth->SetText("Opponent Health: " + std::to_string(opponent->GetHealthPoints()));
	opponentSanity->SetText("Opponent Sanity: " + std::to_string(opponent->GetSanityPoints()));

	opponent->SetPosition(sf::Vector2f(680, 125));
	opponent->SetScale(sf::Vector2f(2, 2));
	AddGameObject(*opponent);
}

void FightScreen::DetermineStart()
{
	if (player->GetAgilityPoints() > opponent->GetAgilityPoints())
	{
		std::cout << "Player starts!" << std::endl;
		playerTurn = true;
	}
	else if (player->GetAgilityPoints() < opponent->GetAgilityPoints())
	{
		std::cout << "Opponent starts!" << std::endl;
		playerTurn = false;
	}
}

void FightScreen::DoAction(const int AttackChance, const int RecoverChance, const int CastMagicChance, const int sum, const int r)
{
	if (r <= AttackChance)
	{
		std::cout << "Opponent Attacks!" << std::endl;
		attackButton->OnClick();
	}
	else if (r > AttackChance && r <= AttackChance + RecoverChance)
	{
		std::cout << "Opponent Recovers!" << std::endl;
		recoverButton->OnClick();
	}
	else if (r > AttackChance + RecoverChance && r <= AttackChance + RecoverChance + CastMagicChance)
	{
		std::cout << "Opponent Casts Magic!" << std::endl;
		castMagicButton->OnClick();
	}
	else if (r > AttackChance + RecoverChance + CastMagicChance && r <= sum)
	{
		std::cout << "Opponent Trembles in fear!" << std::endl;
		opponentActionText->SetText(opponent->GetName() + " trembles in fear and does nothing!");
	}
}

/// <summary>
/// Function for enemy
/// </summary>
void FightScreen::PickAction()
{	
	const auto AttackChance = 35;
	const auto RecoverChance = 10;
	const auto CastMagicChance = 20;
	const auto TrembleInFearChance = 10;

	const auto sum = AttackChance + RecoverChance + CastMagicChance + TrembleInFearChance;

	const auto r = rand() % sum + 1;
	
	DoAction(AttackChance, RecoverChance, CastMagicChance, sum, r);
	playerTurn = true;
}

void FightScreen::Attack(Character* attacker, Character* receiver)
{
	int damage = static_cast<int>(attacker->GetStrengthPoints() + rand() % 4 + 1) - ceil(receiver->GetStrengthPoints() / 2);

	if (damage <= 0)
	{
		damage = 1;
	}

	receiver->TakeHealth(damage);
	
	if (playerTurn)
	{
		playerActionText->SetText(attacker->GetName() + " deals " + std::to_string(damage) + " damage to " + receiver->GetName() + " using Attack!");
		playerTurn = false;
		this->PickAction();
	}
	else
	{
		opponentActionText->SetText(attacker->GetName() + " deals " + std::to_string(damage) + " damage to " + receiver->GetName() + " using Attack!");
	}
}

void FightScreen::Recover(Character* receiver)
{
	if (receiver->GetHealthPoints() != 15 * receiver->GetStrengthPoints())
	{
		auto number = ceil(receiver->GetWitsPoints() * 1.5f) * 11;

		auto r = rand() % 100 + 1;

		if (r < number)
		{
			const auto rH = rand() % 4;
			const auto rS = rand() % 2 + 1;

			if (receiver->GetHealthPoints() + rH > 15 * receiver->GetStrengthPoints())
			{
				const auto points = (15 * receiver->GetStrengthPoints()) - receiver->GetHealthPoints();
				receiver->GainHealth(points);
			}
			else
			{
				receiver->GainHealth(rH);
			}

			if (receiver-> GetSanityPoints() + rS > 9 * receiver->GetSanityPoints())
			{
				const auto points = (9 * receiver->GetSanityPoints()) - receiver->GetSanityPoints();
				receiver->GainSanity(points);
			}
			else
			{
				receiver->GainSanity(rS);
			}

			switch (playerTurn)
			{
			case true:
				playerActionText->SetText(receiver->GetName() + " used Recover and was successful!");
				break;
			case false:
				opponentActionText->SetText(receiver->GetName() + " used Recover and was successful!");
				break;
			}
		}
		else
		{
			switch (playerTurn)
			{
			case true:
				playerActionText->SetText(receiver->GetName() + " used Recover and was not successful!");
				break;
			case false:
				opponentActionText->SetText(receiver->GetName() + " used Recover and was not successful!");
				break;
			}
		}
	}

	std::cout << receiver->GetName() << " health: " << receiver->GetHealthPoints() << std::endl;
	std::cout << std::endl;
	
	if (playerTurn)
	{
		playerTurn = false;
		this->PickAction();
	}
	
}

void FightScreen::CastMagic(Character* attacker, Character* receiver)
{
	auto damage = static_cast<int>(attacker->GetWitsPoints() + rand() % 3 - 3);

	if (damage < 0)
	{
		attacker->TakeSanity(1);
		switch (playerTurn)
		{
		case true:
			playerActionText->SetText(attacker->GetName() + " deals " + std::to_string(1) + " sanity to itself using Cast Magic!");
			break;
		case false:
			opponentActionText->SetText(attacker->GetName() + " deals " + std::to_string(1) + " sanity to itself using Cast Magic!");
			break;
		}
	}
	else
	{
		receiver->TakeHealth(damage);
		switch (playerTurn)
		{
		case true:
			playerActionText->SetText(attacker->GetName() + " deals " + std::to_string(damage) + " damage to " + receiver->GetName() + " using Cast Magic!");
			break;
		case false:
			opponentActionText->SetText(attacker->GetName() + " deals " + std::to_string(damage) + " damage to " + receiver->GetName() + " using Cast Magic!");
			break;
		}
	}

	std::cout << attacker->GetName() << " health: " << attacker->GetHealthPoints() << std::endl;
	std::cout << receiver->GetName() << " health: " << receiver->GetHealthPoints() << std::endl;
	std::cout << std::endl;
	
	if (playerTurn)
	{
		playerTurn = false;
		this->PickAction();
	}
}
