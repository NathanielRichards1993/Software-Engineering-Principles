#include "Image.h"

GLuint Image::texnum[MAX_TEXTURES];

Image::Image()
{
	static int ID = 0;//set id as static int so that each new image will have a different id

	id = ID;//set the image id to the new id

	width = 0;//width of image
	height = 0;//height of image

	ID++;//increment the id so each new one is different
}

Image::~Image()
{
}

void Image::init()//enable openGL texturing and generate the max amount 
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

	image = (unsigned char*)malloc(bitmapHeaderInfo.biSizeImage);//allocate enough memory for the image

	if(!image)
	{
		free(image);
		fclose(f);
		image = NULL;
		return false;
	}

	fread(image, 1, bitmapHeaderInfo.biSizeImage, f);//read the image into memory

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

	width = bitmapHeaderInfo.biWidth;//set width to the pixel width of the bitmap
	height = bitmapHeaderInfo.biHeight;//set height to the pixel height of the bitmap

	glBindTexture(GL_TEXTURE_2D, texnum[id]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

	return true;
}

void Image::draw(float x, float y)//create the image plane and bind texture
{
	glBindTexture(GL_TEXTURE_2D, texnum[id]);

	glBegin(GL_QUADS);
	
	//Texture coords for the image plane

	glTexCoord2i(0, 1); //bottom left
	glVertex2f(x,y);

	glTexCoord2i(0, 0); //top left
	glVertex2f(x, y + height);

	glTexCoord2i(1, 0); //top right
	glVertex2f(x + width, y + height);

	glTexCoord2i(1, 1); //bottom right
	glVertex2f(x + width, y);

	glEnd();
}

int Image::getWidth()//returns the image width for positioning offset
{
	return width;
}

int Image::getHeight()//returns the image height for positioning offset
{
	return height;
}