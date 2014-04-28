#include "Actor.h"

Actor::Actor()
{
}

Actor::~Actor()
{
}

void Actor::setPosition(float x, float y)
{
	position.setX(x);
	position.setY(y);
}

Vector Actor::getPosition()
{
	return position;
}

void Actor::loadTexture(char* filename)//callthrough function for ease of loading enemy and player textures
{
	image.loadTexture(filename);
}