#include"DxLib.h"
#include "SceneResult.h"
#include "SceneTitle.h"

SceneResult::SceneResult()
{
	m_isEnd = false;
}

void SceneResult::update()
{

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_3)
	{
		DxLib_End();				//ゲームを終了する
	}
}

void SceneResult::draw()
{
	DrawString(620, 10, "リザルト画面", GetColor(255, 255, 255));			//タイトル画面の表示
	DrawString(620, 480, "Xボタン", GetColor(255, 255, 255));			//タイトル画面の表示

	DrawString(620, 200, "すべての敵を撃ちました。", GetColor(255, 255, 255));			//タイトル画面の表示

	DrawBox(0, 0, 25, 25, GetColor(255, 255, 255), false);    // 四角形を描画
}