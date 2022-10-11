#pragma once

#include"SceneBase.h"

class SceneManager
{
public:
	// �V�[���̎��
	typedef enum SceneKind
	{
		kSceneKindTitle,		//�^�C�g��
		kSceneKindMain,			//�Q�[�����C�����

	}SceneKind;

public:
	SceneManager();
	virtual ~SceneManager(){}

	void init(SceneKind kind = kSceneKindTitle);
	void end();

	void update();
	void draw();

private:
	SceneKind	m_kind;			//�V�[���̎��
	SceneBase* m_pScene;		//�|�C���^�ŃV�[����n��
};