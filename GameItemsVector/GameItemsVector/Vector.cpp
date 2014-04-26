#include "Vector.h"


Vector::Vector(void)
{
	x = 0;
	y = 0;
}
Vector::Vector(float xValue,float yValue)
{
	x = xValue;
	y = yValue;
}

Vector::~Vector(void)
{
}

void Vector::setX(float xValue)
{
	x = xValue;
}
float Vector::getX(void)
{
	return x;
}

void Vector::setY(float yValue)
{
	y = yValue;
}
float Vector::getY(void)
{
	return y;
}
