#pragma once

class SceneBase			//�x�[�X�N���X�̍쐬
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