#pragma once
#include "ShotBase.h"

class ShotEnemy :public ShotBase
{
public:
	ShotEnemy() {}
	~ShotEnemy() {}

	virtual void start(Vec2 pos);		//�V���b�g�J�n

	virtual void update();				// �X�V
private:

};