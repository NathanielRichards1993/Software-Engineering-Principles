#pragma once
#include "Actor.h"

class Enemy : public Actor
{
public:
	Enemy(float);
	~Enemy();

	void update();
	void draw();

private:
	bool collision;
	Vector target;
};