#pragma once
#include"Vector.h"

class Item
{
private:
	Vector position;
	unsigned int rewardPoints;
	bool powerUp;

public:
	Item(void);
	Item(Vector, int, bool);
	~Item(void);

	Vector getPosition();
	/*x,y*/
	void setPosition(float , float);

	int getRewardPoints();
	bool getPowerUp();

};

