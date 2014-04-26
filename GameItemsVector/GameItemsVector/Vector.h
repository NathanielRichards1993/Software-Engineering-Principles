#pragma once
class Vector
{
private:
	float x;
	float y;
public:
	Vector(void);
	/*x,y coordinates*/
	Vector(float,float);
	~Vector(void);

	void setX(float);
	float getX(void);

	void setY(float);
	float getY(void);
};

// remove this note.
// note need to change class diagram so that the gets and sets use float's and not int's.

