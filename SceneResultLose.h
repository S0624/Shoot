#pragma once
#pragma once
#include"SceneBase.h"
#include"SceneMain.h"

class SceneResultLose : public SceneBase			//�x�[�X�N���X���p�����ă^�C�g���N���X�̍쐬
{
public:
	SceneResultLose();
	virtual ~SceneResultLose() {}

	virtual void init()override { m_isEnd = false; }
	virtual void end()override {}

	virtual void update()override;
	virtual void draw() override;

	virtual bool isEnd()override { return m_isEnd; }
private:
	bool m_isEnd;
};