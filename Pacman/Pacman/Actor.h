#pragma once
#include "Vector.h"
#include "Image.h"

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
	Image image;
	Vector position;
	float speed;
	bool alive;

};