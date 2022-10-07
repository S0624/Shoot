#pragma once
#include"SceneBase.h"

class SceneMain : public SceneBase			//�x�[�X�N���X���p�����ă^�C�g���N���X�̍쐬
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