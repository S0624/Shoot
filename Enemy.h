#pragma once
#include"Vec2.h"

class SceneMain;

class Enemy
{
public:
	Enemy();
	virtual ~Enemy() {}

	void init();				//初期化

	void setMain(SceneMain* pMain) { m_pMain = pMain; }			//クラスポインタを設定

	void update();				//処理
	void draw();				//描画

	void Dead() { m_isDead = true; }

	Vec2 getPos() const { return m_pos; }		//情報の取得
	Vec2 getBottomRight() const { return m_pos + m_size; }		//右上座標の取得

	bool isDead()const { return m_isDead; }
private:
	SceneMain* m_pMain;			//SceneMainのポインタ

	Vec2 m_pos;
	Vec2 m_vec;
	Vec2 m_size;

	//int m_shotInterval;			//ショットの発射間隔

	bool m_isDead;
};