#include "Game.h"
#include <iostream>
#include <string>

void Game::initVars()
{
	this->window = nullptr;
	this->font.loadFromFile("C:/Windows/Fonts/arial.ttf");
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Pong", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initPlayer1()
{
	this->p1_w = 20.0f;
	this->p1_h = 140.0f;
	this->p1X = 5.0f;
	this->p1Y = HEIGHT / 2 - p1_h / 2;

	this->player1.setSize(sf::Vector2f(p1_w, p1_h));
	this->player1.setPosition(sf::Vector2f(p1X, p1Y));
	this->player1.setFillColor(sf::Color(211, 211, 211, 255));
	this->Player1Score.setFont(font);
	this->Player1Score.setString(std::to_string(p1Score));
	
}

void Game::initPlayer2()
{
	this->p2_w = 20.0f;
	this->p2_h = 140.0f;
	this->p2X = (WIDTH - p2_w) - 5;
	this->p2Y = HEIGHT / 2 - p2_h / 2;

	this->player2.setSize(sf::Vector2f(p2_w, p2_h));
	this->player2.setPosition(sf::Vector2f(p2X, p2Y));
	this->player2.setFillColor(sf::Color(211, 211, 211, 255));
	this->Player2Score.setFont(font);
	this->Player2Score.setString(std::to_string(p2Score));
	this->Player2Score.setPosition(880.0f, 0.0f);
}

void Game::initBall()
{
	this->BX = 450.0f;
	this->BY = 300.0f;
	this->BRad = 15.0f;
	this->ball.setRadius(BRad);
	this->ball.setPosition(BX, BY);
	this->ball.setFillColor(sf::Color(150, 150, 150, 255));
}

void Game::initBorder()
{
	this->borderW = 7;
	this->borderH = 600;
	this->border.setSize(sf::Vector2f(borderW, borderH));
	this->border.setPosition(sf::Vector2f(445.0f, 0.0f));
	this->border.setFillColor(sf::Color(211, 211, 211, 255));
}

void Game::MovePlayer1()
{
	sf::Vector2f player1Pos = this->player1.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) & player1Pos.y > 10) {
		player1.move(0.0f, -this->VELOCITY);
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) & player1Pos.y < 449.0f)
	{
		player1.move(0.0f, this->VELOCITY);
		
	}
	
}

void Game::MovePlayer2()
{
	sf::Vector2f player2Pos = this->player2.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) & player2Pos.y > 10) {
		player2.move(0.0f, -this->VELOCITY);
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) & player2Pos.y < 449.0f){
		player2.move(0.0f, this->VELOCITY);
		
	}	
		
}

void Game::BallAnimations()
{
	this->BX += this->B_speed_X;
	this->BY += this->B_speed_Y;
	this->ball.move(this->B_speed_X, this->B_speed_Y);

	if (ball.getGlobalBounds().intersects(player1.getGlobalBounds()) || ball.getGlobalBounds().intersects(player2.getGlobalBounds()))
	{
		this->B_speed_X *= -1;
	}
	
	else if (ball.getPosition().y < 0 || ball.getPosition().y > 600 - ball.getGlobalBounds().width - 5)
	{
		this->B_speed_Y *= -1;
	}
	else if (ball.getPosition().x < 0)
	{
		this->p2Score++;
		this->Player2Score.setString(std::to_string(p2Score));
		this->BX = WIDTH / 2;
		this->BY = HEIGHT / 2;
		this->ball.setPosition(BX, BY);
		Sleep(3000);
		//this->B_speed_X *= -1;
	}
	else if (ball.getPosition().x > 900 - 30)
	{
		this->p1Score++;
		this->Player1Score.setString(std::to_string(p1Score));
		this->BX = WIDTH / 2;
		this->BY = HEIGHT / 2;
		this->ball.setPosition(BX, BY);
		Sleep(3000);
		//this->B_speed_X *= -1;
	}

}
Game::Game()
{
	this->initVars();
	this->initWindow();
	this->initPlayer1();
	this->initPlayer2();
	this->initBall();
	this->initBorder();
	
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}
void Game::pollEvent()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();

		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::update()
{
	this->pollEvent();
	this->MovePlayer1();
	this->MovePlayer2();
	this->BallAnimations();
}

void Game::render()
{
	this->window->clear();

	this->window->draw(player1);
	this->window->draw(player2);
	this->window->draw(ball);
	this->window->draw(border);
	this->window->draw(Player1Score);
	this->window->draw(Player2Score);
	this->window->display();
}
