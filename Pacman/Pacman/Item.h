#pragma once
#include"Vector.h"
#include"Image.h"

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

	/*x,y*/
	Vector getPosition();
	void setPosition(float , float);
	void setRewardPoints(int);

	int getRewardPoints();

	bool getPowerUp();
	void setPowerUp(bool);

	void draw(Image*);
};

