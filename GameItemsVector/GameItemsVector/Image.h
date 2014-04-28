#pragma once
#include <string>
#include <Windows.h>
//#include "glut.h"


#define MAX_TEXTURES  128
#define BITMAP_ID  0x4D42

using namespace std;

class Image
{
public:
	Image();
	~Image();

	bool loadTexture(string);
	void draw(float, float);

	int getWidth();
	int getHeight();

	static void init();
//
//private:
//	static GLuint texnum[MAX_TEXTURES];
//
//	unsigned char* image;
//
//	int width;
//	int height;
//	int id;
};