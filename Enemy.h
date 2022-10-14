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

	Vec2 getPos() const { return m_pos; }		//情報の取得

	virtual float getRadius()const;	//当たり判定の半径の取得
	virtual Vec2 getCenter()const;	//当たり判定の中心位置取得
private:
	SceneMain* m_pMain;			//SceneMainのポインタ

	Vec2 m_pos;
	Vec2 m_vec;
	Vec2 m_size;

	int m_shotInterval;			//ショットの発射間隔
};