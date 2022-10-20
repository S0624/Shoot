#pragma once
#include"Vec2.h"
#include"Enemy.h"

class ShotBase
{
public:
	ShotBase();
	virtual ~ShotBase();

	virtual void start(Vec2 pos);	//ショット開始

	virtual void update();			// 更新
	virtual void draw();			// 表示

	Vec2 getPos() const { return m_pos; }		//情報の取得
	Vec2 getBottomRight() const { return m_pos + m_size; }		//右上座標の取得

protected:
	Vec2	m_pos;					// 表示位置
	Vec2	m_vec;					// 移動
	Vec2	m_size;					// サイズ
	bool m_isExist;					//存在するか
};