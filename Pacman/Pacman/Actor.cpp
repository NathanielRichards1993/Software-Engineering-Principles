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