#include "Player.h"

Player::Player(int lives)
{
	this->lives = lives; 
}

Player::~Player()
{
}

bool Player::getPowerUp()
{
	return powerUp;
}

void Player::setPowerUp(bool powerUp)
{
	this->powerUp = powerUp;
}

void Player::update()
{
}

void Player::draw()
{
}