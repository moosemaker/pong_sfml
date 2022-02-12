#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game
{

private:
	// window
	sf::RenderWindow* window;
	Player player1;
	Player player2;
	sf::Event ev;

	void initVars();
	void initWindow();
	void initPlayer1();
	void initPlayer2();
public:
	Game();

	~Game();

	const bool running() const;

	//function
	void pollEvent();
	void update();
	void render();

};

