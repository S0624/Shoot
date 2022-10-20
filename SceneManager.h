#pragma once

#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneResultLose.h"

class SceneManager
{
public:
	// シーンの種類
	typedef enum SceneKind
	{
		kSceneKindTitle,		//タイトル
		kSceneKindMain,			//ゲームメイン画面
		kSceneKindResultLose,			//リザルト画面

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
	SceneKind	m_kind;			//シーンの種類
	
	SceneTitle m_title;
	SceneMain m_main;
	SceneResultLose m_lose;
};