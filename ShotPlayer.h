#pragma once
#include "ShotBase.h"

class ShotPlayer :public ShotBase
{
public:
	ShotPlayer(){}
	~ShotPlayer(){}

	virtual void start(Vec2 pos);		//ショット開始

	virtual void update();				// 更新
private:

};