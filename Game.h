#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <random>
#include <Windows.h>

class Game
{

private:
	// window
	sf::RenderWindow* window;
	
	sf::Event ev;
	sf::RectangleShape player1;
	sf::RectangleShape player2;
	sf::CircleShape ball;
	

	float p1X, p1Y, p1_w, p1_h;
	float p2X, p2Y, p2_w, p2_h;
	float BRad, BSides, BX, BY;
	float B_speed_X = -3.0f, B_speed_Y = 3.0f;
	int p1Score = 0, p2Score = 0;

	sf::FloatRect player1Bounds = this->player1.getGlobalBounds();
	sf::FloatRect player2Bounds = this->player2.getGlobalBounds();
	sf::FloatRect ballBounds = this->ball.getGlobalBounds();

	float VELOCITY = 7;

	void initVars();
	void initWindow();
	void initPlayer1();
	void initPlayer2();
	void initBall();

	void MovePlayer1();
	void MovePlayer2();
	void resetPosOfBall();
	void BallAnimations();
	
	
public:
	Game();

	~Game();

	const bool running() const;

	//function
	void pollEvent();
	void update();
	void render();

};

