#pragma once

#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneResultLose.h"

class SceneManager
{
public:
	// �V�[���̎��
	typedef enum SceneKind
	{
		kSceneKindTitle,		//�^�C�g��
		kSceneKindMain,			//�Q�[�����C�����
		kSceneKindResultLose,			//���U���g���

	}SceneKind;

public:
	SceneManager();
	virtual ~SceneManager(){}

	void init(SceneKind kind = kSceneKindTitle);
	//void init(SceneKind kind = kSceneKindMain);
	void end();

	void update();
	void draw();

private:
	SceneKind	m_kind;			//�V�[���̎��
	
	SceneTitle m_title;
	SceneMain m_main;
	SceneResultLose m_lose;
};