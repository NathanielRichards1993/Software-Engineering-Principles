#include "Game.h"

//spawn for enemies in the center is as below (E = enemy)
//E E  
//E E
//center of the screen = 0,0 in x,y 

//create all enemies,items,main_menu,highscore_menu and player.
Game::Game(void)
{
	//Bottom Left
	Vector vector = Vector(-COLLISION_DISTANCE,-COLLISION_DISTANCE);
	enemies[0] = new Enemy(vector);
	//(-,-)

	//Bottom Right
	vector.setX(COLLISION_DISTANCE);
	enemies[1] = new Enemy(vector);
	//(+,-)

	//Top Right
	vector.setY(COLLISION_DISTANCE);
	enemies[2] = new Enemy(vector);
	//(+,+)

	//Top Left
	vector.setX(-COLLISION_DISTANCE);
	enemies[3] = new Enemy(vector);
	//(-,+)

	vector.setX(0);
	vector.setY(0);

	//sets all the item position to (0,0),
	//all reward points are 0 and powerUp state equal false.
	for(int i = 0; i< MAX_ENEMIES; i++)
	{
		items[i] = new Item(vector,0,false);
	}

	//create player and sets it's score to 0.
	//Need to see if player constructor should recieve a vector??? or use a set??
	pPlayer = new Player(0);
	pPlayer->setPosition(50,50);
	pPlayer->setPowerUp(false);
	//might take out last 2 lines if constructor of player does those lines
	//ask lloyd what he wants to do.

	//2 menu created which 1 gives keyboard control.
	//or is that going to be moved to game class.
	main = new Main_Menu();
	highScore = new HighScore_Menu();

}


Game::~Game(void)
{
}

//////////////////////////////////////////////////////////
int Game::getScore(void)
{
	return score;
}
/////////////////////////////////////////////////////////
void loadLevel(string fileName)
{

}
/////////////////////////////////////////////////////////
void update()
{

}
/////////////////////////////////////////////////////////