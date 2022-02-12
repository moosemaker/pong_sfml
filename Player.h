#pragma once
#include "Game.h"
class Player
{
private:
	// vars
	float paddle_w, paddle_h;
	sf::RectangleShape paddle;
	//functions
	void initPlayer();
public:
	float playerX, playerY;
	Player();

	sf::Vector2f getPosOfPlayer();
};

