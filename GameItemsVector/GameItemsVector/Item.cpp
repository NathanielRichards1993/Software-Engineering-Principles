#include "Item.h"

///////////////////////////////////////////////////
Item::Item(void)
{
}
Item::Item(Vector itemPosition, int points, bool isPowerUp)
{
	position = itemPosition;
	rewardPoints = points;
	powerUp = isPowerUp;
}
////////////////////////////////////////////////////
Item::~Item(void)
{
	position.setX(0);
	position.setY(0);

	rewardPoints = 0;
	powerUp = 0;
}
////////////////////////////////////////////////////
Vector Item::getPosition()
{
	return position;
}
void Item::setPosition(float x, float y)
{
	position.setX(x);
	position.setY(y);
}
////////////////////////////////////////////////////
int Item::getRewardPoints()
{
	return rewardPoints;
}
////////////////////////////////////////////////////
bool Item::getPowerUp()
{
	return powerUp;
}
////////////////////////////////////////////////////