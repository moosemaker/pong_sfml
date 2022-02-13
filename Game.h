#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <random>
#include <Windows.h>
#include <windows.data.json.h>

class Game
{

private:
	// window
	sf::RenderWindow* window;
	
	sf::Event ev;
	sf::RectangleShape player1;
	sf::RectangleShape player2;
	sf::CircleShape ball;
	sf::RectangleShape border;
	sf::Font font;
	sf::Text Player1Score;
	sf::Text Player2Score;

	float p1X, p1Y, p1_w, p1_h;
	float p2X, p2Y, p2_w, p2_h;
	float BRad, BX, BY;
	float srtPosXBor, srtPosYBor;
	float borderW, borderH;
	float B_speed_X = -20.0f, B_speed_Y = 20.0f;
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
	void initBorder();

	void MovePlayer1();
	void MovePlayer2();

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

