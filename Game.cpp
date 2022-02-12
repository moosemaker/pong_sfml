#include "Game.h"
#include <iostream>

void Game::initVars()
{
	this->window = nullptr;

}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(900, 600), "Pong", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initPlayer1()
{
	this->p1_w = 20.0f;
	this->p1_h = 140.0f;
	this->p1X = 5.0f;
	this->p1Y = 600 / 2 - p1_h / 2;

	this->player1.setSize(sf::Vector2f(p1_w, p1_h));
	this->player1.setPosition(sf::Vector2f(p1X, p1Y));
	this->player1.setFillColor(sf::Color(211, 211, 211, 255));
}

void Game::initPlayer2()
{
	this->p2_w = 20.0f;
	this->p2_h = 140.0f;
	this->p2X = (900 - p2_w) - 5;
	this->p2Y = 600 / 2 - p2_h / 2;

	this->player2.setSize(sf::Vector2f(p2_w, p2_h));
	this->player2.setPosition(sf::Vector2f(p2X, p2Y));
	this->player2.setFillColor(sf::Color(211, 211, 211, 255));
}

void Game::MovePlayer1()
{
	sf::Vector2f player1Pos = this->player1.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) & player1Pos.y > 10) {
		player1.move(0.0f, -this->VELOCITY);
		std::cout << player1Pos.x << " " << player1Pos.y << std::endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) & player1Pos.y < 449.0f)
	{
		player1.move(0.0f, this->VELOCITY);
		std::cout << player1Pos.x << " " << player1Pos.y << std::endl;
	}
	
}

void Game::MovePlayer2()
{
	sf::Vector2f player2Pos = this->player2.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) & player2Pos.y > 10)
		player2.move(0.0f, -this->VELOCITY);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) & player2Pos.y < 449.0f)
		player2.move(0.0f, this->VELOCITY);
}


void Game::player2WindowBoundsCollsion()
{
	sf::Vector2f player2Pos = this->player2.getPosition();
	if (this->player2Bounds.top <= 0) {
		this->player2.setPosition(895.0f - player1Bounds.width, player2Pos.y);
	}
	else if (this->player2Bounds.top - player2Bounds.height - 5 >= 595.0f) {
		this->player2.setPosition(895.0f, 595 - this->player2Bounds.height);
	}
}

Game::Game()
{
	this->initVars();
	this->initWindow();
	this->initPlayer1();
	this->initPlayer2();

	
	
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
}

void Game::render()
{
	this->window->clear();
	this->window->draw(player1);
	this->window->draw(player2);
	this->window->display();
}
