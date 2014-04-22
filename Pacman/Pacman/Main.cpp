#include "Image.h"

void init(void);
void display(void);
void reshape(int, int);
void update(void);
void keyboard(unsigned char, int, int);

Image pacman;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);

	//Window setup
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Pacman");

	Image::init();

	pacman.loadTexture("Pacman.bmp");
	pacman.draw(10,10);

	//init();

	//Glut functions
	glutIdleFunc(update);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}

void init()//wrapper to call through to game.init() for enemy/player initilisation
{
	//game.init();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	//game.draw();

	glutSwapBuffers();
}

void update()
{
	//calls display in order to call through to game.draw();
	glutPostRedisplay();
}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//enable 2D
	glOrtho(0, width, height, 0, -1, 1);
}

void keyboard(unsigned char key, int x, int y)//wrapper function so the game can be controlled via the keyboard from game class
{
	//game.keyboard(key, x, y);
}