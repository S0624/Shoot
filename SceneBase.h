#pragma once

class SceneBase			//ベースクラスの作成
{
public:
	SceneBase(){}
	virtual ~SceneBase(){}

	virtual void init(){}
	virtual void end(){}

	virtual void update(){};
	virtual void draw(){}

	virtual bool isEnd() { return false; }
protected:

};