#pragma once
#include"SceneBase.h"

class SceneMain : public SceneBase			//ベースクラスを継承してタイトルクラスの作成
{
public:
	SceneMain();
	virtual ~SceneMain() {}

	virtual void init();
	virtual void end();

	virtual void update();
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
private:
	bool m_isEnd;

};