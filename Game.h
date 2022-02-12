#pragma once
#include <SFML/Graphics.hpp>


class Game
{

private:
	// window
	sf::RenderWindow* window;
	
	sf::Event ev;
	sf::RectangleShape player1;
	sf::RectangleShape player2;

	float p1X, p1Y, p1_w, p1_h;
	float p2X, p2Y, p2_w, p2_h;

	sf::FloatRect player1Bounds = this->player1.getGlobalBounds();
	sf::FloatRect player2Bounds = this->player2.getGlobalBounds();

	float VELOCITY = 7;

	void initVars();
	void initWindow();
	void initPlayer1();
	void initPlayer2();

	void MovePlayer1();
	void MovePlayer2();

	void player1WindowBoundsCollsion();
	void player2WindowBoundsCollsion();
	
	
public:
	Game();

	~Game();

	const bool running() const;

	//function
	void pollEvent();
	void update();
	void render();

};

