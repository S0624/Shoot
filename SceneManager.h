#pragma once

#include"SceneBase.h"

class SceneManager
{
public:
	// シーンの種類
	typedef enum SceneKind
	{
		kSceneKindTitle,		//タイトル
		kSceneKindMain,			//ゲームメイン画面

	}SceneKind;

public:
	SceneManager();
	virtual ~SceneManager(){}

	void init(SceneKind kind = kSceneKindTitle);
	void end();

	void update();
	void draw();

private:
	SceneKind	m_kind;			//シーンの種類
	SceneBase* m_pScene;		//ポインタでシーンを渡す
};