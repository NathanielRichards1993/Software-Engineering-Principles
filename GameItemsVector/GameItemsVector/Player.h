#pragma once
#include"Vector.h"
class Player
{
private:

public:
	Player(void);
	~Player(void);
	Player(int);
	bool getPowerUp(void);
	void setPowerUp(bool);
	void update(void);
	void draw(void);

	void setPosition(float,float);
	Vector getPosition(void);

	bool getAlive();

	Vector getDirection();
};

//update has been removed and all the logic is handle be game

