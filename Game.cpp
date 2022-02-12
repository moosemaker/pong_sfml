#include "Game.h"

void Game::initVars()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(900, 600), "Pong", sf::Style::Titlebar | sf::Style::Close);
}

Game::Game()
{
	this->initVars();
	this->initWindow();
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
	
	this->window->display();
}
