#pragma once
#include"Vector.h"
class Enemy
{
private:
public:
	Enemy(void);
	~Enemy(void);
	Enemy(Vector);
	void update(void);
	void draw(void);
	void setPosition(float,float);
	Vector getPosition(void);
};

