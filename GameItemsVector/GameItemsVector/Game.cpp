#include "Game.h"
#include<fstream>//only include in this cpp because it should not be used by any other cpp.

//create all enemies,items,main_menu,highscore_menu and player.
Game::Game(void)
{
	Vector vector = Vector(0,0);
	//sets all the item position to (0,0),
	//all reward points are 0 and powerUp state equal false.
	for(int i = 0; i< MAX_ITEMS; i++)
	{
		items[i] = new Item(vector,0,false);
	}

	for(int i = 0; i<MAX_ENEMIES; i++)
	{
		enemies[i] = new Enemy();
	}

	//create player and sets it's score to 0.
	pPlayer = new Player();
	pPlayer->setPosition(0,0);

	//2 menu created which 1 gives keyboard control.
	//or is that going to be moved to game class.
	main = new Main_Menu();
	highScore = new HighScore_Menu();

	//shoudl; start with the player going to the left
	playerDirection = Vector(-1,0);

	wall = new Image();
	food = new Image();
	blank = new Image();
	powerUp = new Image();
}

//frees up memory and uses delete for all cause all used new.
Game::~Game(void)
{

	for(int i = 0; i < MAX_ENEMIES; i++)
	{
		delete(enemies[i]);
	}

	delete(pPlayer);
	delete(main);
	delete(highScore);
}

//////////////////////////////////////////////////////////
//returns players score.
int Game::getScore(void)
{
	return score;
}
/////////////////////////////////////////////////////////
//reads in the level of the map and receives the name of the file that stores the level.
void Game::loadLevel(char* fileName)
{
	fstream myfile;
	myfile.open(fileName);

	if(myfile.eof())
	{
	}
	else
	{
		while(!myfile.eof())
		{
			for(int i=0; i<MAP_SIZE; i++)
			{
				myfile >> mapArray[i];
			}
		}
	}
}
/////////////////////////////////////////////////////////
//this should update the players movement, enemies movement and also do all collision.
void Game::update()
{

	Vector playerLocation = pPlayer->getPosition();

	//check player aginst all walls

	Vector playerMoveToLocation = Vector (playerLocation.getX() + playerDirection.getX(),
		playerLocation.getX() + playerDirection.getX());



	for(int i = 0; i < MAP_SIZE; i++)
	{

	}


}
/////////////////////////////////////////////////////////
// this is going to check for collisiion of a moving object aginst a static
// will not be done till drawing of the objects to the screen is done first.
bool Game::checkCollision(Vector movingObject,Vector movingDirection,Vector stationaryObject)
{
	if(movingObject.getX() != 0)
		{
		//going right
			if(movingDirection.getX() > 0)
		{

		}
		else
		{
			//going left

		}
	}
	else
	{
		if(movingDirection.getY() != 0)
		{
			//going Up
			if(movingDirection.getY() > 0)
			{

			}
			else
			{
				//going down

			}
		}
		else
		{
			//player has stopped most likely hit a wall or killed.
		}

	}
	return false;
}
///////////////////////////////////////////////////////////////
//should set where all items are and also where the enemies spawn and player spawns. 
void Game::Int()
{
	int itemCounter = 0;
	int enemyCounter = 0;
	//items are x or 1, player is P and enemy spawn is S

	for(int j = 0; j < MAP_SIZE; j++)
	{
		for(int i = 0; i < MAP_SIZE; i++)
		{
			if(mapArray[j][i] == '0' || mapArray[j][i] == 'X')
			{
				items[itemCounter]->setPosition((i+1)*(PICTURE_SIZE),(j+1)*(PICTURE_SIZE));
				itemCounter++;
				if(mapArray[j][i] == 'X')
				{
					items[itemCounter]->setPowerUp(true);
				}
				else
				{
					// nothing power up state shold already be set to false.
				}
			}
			else if(mapArray[j][i] == 'S')
			{
				enemies[enemyCounter]->setPosition((j+1)*(PICTURE_SIZE),(i+1)*(PICTURE_SIZE));
				enemyCounter++;
			}
			else if(mapArray[j][i] == 'P')
			{
				pPlayer->setPosition((j+1)*(PICTURE_SIZE),(i+1)*(PICTURE_SIZE));
			}
		}
	}

	wall->loadTexture("wall.bmp");
	blank->loadTexture("blank.bmp");
	food->loadTexture("food.bmp");
	powerUp->loadTexture("powerUp.bmp");

}
////////////////////////////////////////////////////////////////
// this should call draws on player, enemies, items and draw the wall.
void Game::draw()
{
	for(int i = 0; i < MAX_ITEMS; i++)
	{
		if (items[i]->getPowerUp() == true)
		{//draw PowerUp
			items[i]->draw(powerUp);
		}
		else 
		{
			//draw blanck
			if(items[i]->getRewardPoints() == 0)
			{
				items[i]->draw(blank);
			}
			else
			{//draw food
				items[i]->draw(food);
			}
		}
	}

	// j is y axis and i is x axis 
	for(int j = 0; j < MAP_SIZE; j++)
	{
		for(int i = 0; i < MAP_SIZE; i++)
		{
			if(mapArray[j][i] == '1')
			{
				wall->draw((i+1)*(PICTURE_SIZE),(j+1)*(PICTURE_SIZE));
			}
		}
	}

	for(int i = 0; i < MAX_ENEMIES; i++)
	{
		enemies[i]->draw();
	}

	pPlayer->draw();
}