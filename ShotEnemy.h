#pragma once
#include "ShotBase.h"

class ShotEnemy :public ShotBase
{
public:
	ShotEnemy() {}
	~ShotEnemy() {}

	virtual void start(Vec2 pos);		//ショット開始

	virtual void update();				// 更新
private:

};