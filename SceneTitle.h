#pragma once
#include"SceneBase.h"

class SceneTitle : public SceneBase			//ベースクラスを継承してタイトルクラスの作成
{
public:
	SceneTitle();
	virtual ~SceneTitle(){}

	virtual void init();
	virtual void end();

	virtual void update();
	virtual void draw();

	virtual bool isEnd() { return m_isEnd; }
private:
	bool m_isEnd;

};