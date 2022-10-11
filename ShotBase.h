#pragma once
#include"Vec2.h"

class ShotBase
{
public:
	ShotBase();
	~ShotBase();

	//ショット開始
	virtual void start(Vec2 pos);

	// 更新
	virtual void update();
	// 表示
	virtual void draw();

	//存在するか
	bool isExsist()const { return m_isExist; }

protected:
	// 表示位置
	Vec2	m_pos;
	// 移動
	Vec2	m_vec;
	//存在するか
	bool m_isExist;
};