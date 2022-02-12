#include "Player.h"

void Player::initPlayer()
{
	this->paddle_w = 20.0f;
	this->paddle_h = 100.0f;
	this->paddle.setSize(sf::Vector2f(this->paddle_w, this->paddle_h));

	this->paddle.setPosition(sf::Vector2f(this->playerX, this->playerY));
	this->paddle.setFillColor(sf::Color(211, 211, 211, 255));

}

Player::Player()
{
	this->initPlayer();
}


sf::Vector2f Player::getPosOfPlayer()
{
	return this->paddle.getPosition();
}
