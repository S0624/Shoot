#pragma once
#include "ShotBase.h"

class ShotPlayer :public ShotBase
{
public:
	ShotPlayer(){}
	~ShotPlayer(){}

	virtual void start(Vec2 pos);		//�V���b�g�J�n

	virtual void update();				// �X�V
private:

};