#pragma once
class Player
{
public:
	Player(void);
	~Player(void);
	Player(int);
	bool getPowerUp(void);
	void setPowerUp(bool);
	void update(void);
	void draw(void);

	void setPosition(float,float);
	Vector getPosition(void);
};

