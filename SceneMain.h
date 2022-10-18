#pragma once
#include<vector>
#include"SceneBase.h"
#include"ShotBase.h"
#include"Player.h"
#include"Enemy.h"

class SceneMain : public SceneBase			//ベースクラスを継承してタイトルクラスの作成
{
public:
	SceneMain();
	virtual ~SceneMain() {}

	void init();
	void end();

	void update();
	void draw();

	bool isEnd() { return m_isEnd; }
	
	bool createShotPlayer(Vec2 pos);
	//bool createShotEnemy(Vec2 pos);

	bool isCol();            //Collision

private:
	bool m_isEnd;

	float basePosX;
	float basePosY;
	float baseDownX;
	float baseDownY;

	//ShotBase m_base;
	Player m_player;
	Enemy m_enemy;

	std::vector< ShotBase*> m_pShotVt;
	std::vector< ShotBase*> m_eShotVt;
};