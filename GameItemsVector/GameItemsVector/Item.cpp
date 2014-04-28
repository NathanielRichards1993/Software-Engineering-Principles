#include "Item.h"

///////////////////////////////////////////////////
// default sets position to 0,0 and points to 0 and pwoerUp to 0.
Item::Item(void)
{
	position = Vector(0,0);
	rewardPoints = 0;
	powerUp = 0;
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
	// there is no pointers that items deals with so no need for free or deletes
}
////////////////////////////////////////////////////
//return the position of the item as a vector
Vector Item::getPosition()
{
	return position;
}
// sets the position of the item in the position vector object.
void Item::setPosition(float x, float y)
{
	position.setX(x);
	position.setY(y);
}
////////////////////////////////////////////////////
// returns the amount of reward points for this item.
int Item::getRewardPoints()
{
	return rewardPoints;
}
////////////////////////////////////////////////////
//Sets the reward points to what ever is sent in
void Item::setRewardPoints(int points)
{
	rewardPoints = points;
}
////////////////////////////////////////////////////
// returns the bool state of powerUp
bool Item::getPowerUp()
{
	return powerUp;
}
////////////////////////////////////////////////////
// sets the power up bool to what ever it is sent.
void Item::setPowerUp(bool state)
{
	powerUp = state;
}

////////////////////////////////////////////////////
// draws image that has been sent.
void Item::draw(Image* image)
{
	image->draw(position.getX(),position.getY());
}
