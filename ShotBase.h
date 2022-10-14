#pragma once
#include"Vec2.h"

class ShotBase
{
public:
	ShotBase();
	virtual ~ShotBase();

	virtual void start(Vec2 pos);	//ショット開始

	virtual void update();			// 更新
	virtual void draw();			// 表示

	virtual float getRadius()const;	//当たり判定の半径の取得
	virtual Vec2 getCenter()const;	//当たり判定の中心位置取得

	bool isExsist()const { return m_isExist; }	//存在するか

protected:
	Vec2	m_pos;					// 表示位置
	Vec2	m_vec;					// 移動
	Vec2	m_size;					// サイズ
	bool m_isExist;					//存在するか
};