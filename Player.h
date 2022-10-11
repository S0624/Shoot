#pragma once
#include"Vec2.h"


class Player
{
public:
	Player();
	virtual ~Player();

	virtual void init();
	virtual void update();
	virtual void draw();


private:
	Vec2 m_pos;
	Vec2 m_vec;
	Vec2 m_size;

};