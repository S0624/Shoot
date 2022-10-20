#include"DxLib.h"
#include "SceneResultLose.h"
#include "SceneTitle.h"

SceneResultLose::SceneResultLose()
{
	m_isEnd = false;
}

void SceneResultLose::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_3)
	{
		DxLib_End();				//ボタンが押されたらゲームを終了する
	}
}

void SceneResultLose::draw()
{
	DrawString(600, 200, "リザルト", GetColor(255, 255, 255));			//リザルト画面の表示
	DrawString(600, 500, "Xボタン or C key", GetColor(255, 255, 255));			//押すボタンの表示画面の表示
	DrawString(600, 450, "すべての敵を撃てませんでした。", GetColor(255, 255, 255));			//結果の表示	
}