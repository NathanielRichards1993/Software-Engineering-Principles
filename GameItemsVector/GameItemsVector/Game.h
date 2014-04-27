#pragma once
#pragma once

#include<string>

#include"Item.h"
#include"Player.h"
#include"Enemy.h"
#include"Main_Menu.h"
#include"HighScore_Menu.h"

#define MAX_ITEMS 244
#define MAX_ENEMIES 4

// need to confirm the change to allow the define that is used for collision
#define COLLISION_DISTANCE 10
// might be best to have this #define as a static constant

using namespace std;

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

public:
	Game(void);
	~Game(void);

	int getScore(void);
	void loadLevel(string);
	void update();
};

