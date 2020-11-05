#pragma once
#include "../Components/Scene.hpp"
#include "../Components/SpriteObject.hpp"

class StartScreen : public Scene
{
private:
	
public:
	StartScreen(std::string identifier);
	~StartScreen();

	SpriteObject* background;
};
