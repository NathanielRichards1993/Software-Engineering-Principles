#pragma once
#include"Vector.h"
class Enemy
{
private:
public:
	Enemy(void);
	~Enemy(void);
	Enemy(Vector);

	void draw(void);

	void setPosition(float,float);
	Vector getPosition(void);

	Vector getDirection();
};

//update has been removed and all the logic is handle be game

