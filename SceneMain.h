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

	int survivalNum() { return m_enemyNum; };
	int ShotNum() { return shotCountDown; }

	bool isEnd() { return m_isEnd; }
	
	bool createShotPlayer(Vec2 pos);

	bool isCol();            //Collision


private:

	Player m_player;
	int m_enemyNum;

	int shotNumCount;
	int shotCountDown;

	bool m_isEnd;
	// ショット
	std::vector< ShotBase*> m_pShotVt;
};