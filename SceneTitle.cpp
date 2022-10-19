#include"DxLib.h"
#include "SceneTitle.h"
#include "SceneMain.h"

SceneTitle::SceneTitle()
{
	m_isEnd = false;
}

void SceneTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_4)
	{
		m_isEnd = true;					//mainに切り替え
	}
}

void SceneTitle::draw()
{
	DrawString(620, 380, "タイトル画面", GetColor(255, 255, 255));			//タイトル画面の表示
	DrawString(620, 480, "Y or KEY Aボタン", GetColor(255, 255, 255));			//タイトル画面の表示
	
	DrawBox(0, 0, 25, 25, GetColor(255,255,255), false);    // 四角形を描画
}