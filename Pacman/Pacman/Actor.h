#pragma once
#include "Vector.h"

class Actor
{
public:
	Actor();
	~Actor();

	void setPosition(float, float);
	Vector getPosition();

	virtual void update() = 0;
	virtual void draw() = 0;

private:

protected:
	Vector position;
	float speed;
	bool alive;

};