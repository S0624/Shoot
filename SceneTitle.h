#pragma once
#include"SceneBase.h"

class SceneTitle : public SceneBase			//ベースクラスを継承してタイトルクラスの作成
{
public:
	SceneTitle();
	virtual ~SceneTitle(){}

	virtual void init()override { m_isEnd = false; }
	virtual void end()override {}

	virtual void update()override;
	virtual void draw() override;

	virtual bool isEnd()override { return m_isEnd; }
private:
	bool m_isEnd;

};