#include "Image.h"

GLuint Image::texnum[MAX_TEXTURES];

Image::Image()
{
	static int ID = 0;

	id = ID;

	width = 0;
	height = 0;

	ID++;
}

Image::~Image()
{
}

void Image::init()
{
	glEnable(GL_TEXTURE_2D);

	glGenTextures(MAX_TEXTURES, texnum);
}

bool Image::loadTexture(string filename)
{
	BITMAPFILEHEADER bitmapHeader;
	BITMAPINFOHEADER bitmapHeaderInfo;

	FILE * f = fopen(filename.c_str(), "rb");
	if(f == NULL)
	{
		image = NULL;
		return false;
	}

	fread(&bitmapHeader, sizeof(BITMAPFILEHEADER), 1, f);
	if(bitmapHeader.bfType != BITMAP_ID)
	{
		fclose(f);
		image = NULL;
		return false;
	}

	fread(&bitmapHeaderInfo, sizeof(BITMAPINFOHEADER), 1, f);

	fseek(f, bitmapHeader.bfOffBits, SEEK_SET);

	image = (unsigned char*)malloc(bitmapHeaderInfo.biSizeImage);

	if(!image)
	{
		free(image);
		fclose(f);
		image = NULL;
		return false;
	}

	fread(image, 1, bitmapHeaderInfo.biSizeImage, f);

	if(image == NULL)
	{
		fclose(f);
		return false;
	}

	unsigned char temp;

	for(int i = 0; i < (int) bitmapHeaderInfo.biSizeImage; i += 3)
	{
		temp = image[i];
		image[i] = image[i + 2];
		image[i + 2] = temp;
	}

	fclose(f);

	width = bitmapHeaderInfo.biWidth;
	height = bitmapHeaderInfo.biHeight;

	glBindTexture(GL_TEXTURE_2D, texnum[id]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_PROXY_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

	return true;
}

void Image::draw(float x, float y)
{
	glBindTexture(GL_TEXTURE_2D, texnum[id]);

	glBegin(GL_QUADS);
	
	glTexCoord2i(0, 1);
	glVertex2f(x,y);

	glTexCoord2i(0, 0);
	glVertex2f(x, y + height);

	glTexCoord2i(1, 0);
	glVertex2f(x + width, y + height);

	glTexCoord2i(1, 1);
	glVertex2f(x + width, y);

	glEnd();
}

int Image::getWidth()
{
	return width;
}

int Image::getHeight()
{
	return height;
}