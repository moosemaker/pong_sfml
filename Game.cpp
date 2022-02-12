#include "Game.h"

void Game::initVars()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(900, 600), "Pong", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initPlayer1()
{
	this->player1.playerX = 5.0f;
	this->player1.playerY = 600 / 2 - this->player1.paddle_h / 2;

}

void Game::initPlayer2()
{
	this->player2.playerX = 900.0f - 10;
	this->player2.playerY = 600 / 2 - this->player2.paddle_h / 2;
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
}

void Game::render()
{
	this->window->clear();
	this->window->draw(this->player1);
	this->window->display();
}
