#pragma once
#include "Actor.h"

class Player : public Actor
{
public:
	Player();
	~Player();

	bool getPowerUp();
	void setPowerUp(bool);
	
	void update();
	void draw();

private:
	bool powerUp;
	int lives;
};