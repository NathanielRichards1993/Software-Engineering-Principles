#pragma once

class Vector
{
public:
	Vector();
	Vector(float, float);
	~Vector();

	void setX(float);
	float getX();

	void setY(float);
	float getY();

private:
	float x;
	float y;
};