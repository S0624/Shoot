#pragma once
#include"SceneBase.h"
#include"Player.h"

class SceneMain : public SceneBase			//�x�[�X�N���X���p�����ă^�C�g���N���X�̍쐬
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