#pragma once

#include"Item.h"
#include"Player.h"
#include"Enemy.h"
#include"Main_Menu.h"
#include"HighScore_Menu.h"

#define MAX_ITEMS 183
// 4 power ups and the rest are food.


#define MAX_ENEMIES 4
#define MAP_SIZE 19 // Needed for the reading of the the map
#define OBJECT_DISTANCE 10 // this is used for collision detection between walls players and A.i.

// need to confirm the change to allow the define that is used for collision
#define COLLISION_DISTANCE 10
// might be best to have this #define as a static constant

class Game
{
private:
	// score should never go below 0.
	unsigned int score;

	//Pointers to access/use enemies, items, player, main menu and highscore menu.
	Enemy* enemies[MAX_ENEMIES];
	Item* items[MAX_ITEMS];
	Player* pPlayer;
	Main_Menu* main;
	HighScore_Menu* highScore;
	/*Y,X*/
	char mapArray[MAP_SIZE][MAP_SIZE];
	Vector playerDirection;

	//moving object, moving direction,stationery object 
	bool checkCollision(Vector,Vector,Vector);

	Image* wall;
	Image* blank;
	Image* food;
	Image* powerUp;
public:
	Game(void);
	~Game(void);

	int getScore(void);
	void loadLevel(char*);
	void update();
	void KeyBoardInput();
	void Int();
	void draw();
};

