#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game
{

private:
	// window
	sf::RenderWindow* window;
	sf::Event ev;

	void initVars();
	void initWindow();
public:
	Game();

	~Game();

	const bool running() const;

	//function
	void pollEvent();
	void update();
	void render();

};

