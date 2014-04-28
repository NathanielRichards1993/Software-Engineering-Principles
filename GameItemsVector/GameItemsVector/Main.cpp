#include"Game.h"
using namespace std;

void main(void)
{
	Game* game = new Game();
	game->loadLevel("MAP.txt");
	game->Int();
	getchar();
	getchar();
}