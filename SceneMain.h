#pragma once
#include"SceneBase.h"
#include"Player.h"

class SceneMain : public SceneBase			//ベースクラスを継承してタイトルクラスの作成
{
public:
	SceneMain();
	virtual ~SceneMain() {}

	virtual void init()override { m_isEnd = false; }
	virtual void end()override{};

	virtual SceneBase* update()override;
	virtual void draw()override;

	virtual bool isEnd()override { return m_isEnd; }
private:
	bool m_isEnd;

	Player player;
};