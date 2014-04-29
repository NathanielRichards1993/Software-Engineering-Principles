#include <iostream>
using namespace std;
#include <string>
#include "HighScore_Menu.h"
#include "Main_Menu.h"
#include "Menu.h"


void main (void)
{
	Main_Menu testMain;
	HighScore_Menu testHighScore;

	//Test 1
	testMain.addItem("item 1\n");
	testMain.addItem("item 2\n");
	testMain.addItem("overflow item\n");

	for (int i = 0; i < 2; i++)
	{
		cout<<testMain.items[i],"\n";
	}
	//If the test is successful the third item should not be added and
	//"Max items reached" should be printed to the screen


	//Test 2
	testHighScore.addItem("item 1\n");
	testHighScore.addItem("item 2\n");
	testHighScore.addItem("overflow item\n");

	for (int i = 0; i < 2; i++)
	{
		cout<<testHighScore.items[i],"\n";
	}
	//If the test is successful the third item should not be added and
	//"Max items reached" should be printed to the screen

}