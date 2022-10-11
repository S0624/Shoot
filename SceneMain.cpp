#include"DxLib.h"
#include "SceneMain.h"
#include"SceneTitle.h"

SceneMain::SceneMain()
{
	m_isEnd = false;
}


SceneBase* SceneMain::update()
{
	/*int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_2)
	{
		return (new SceneTitle);
	}*/
	return this;
}


void SceneMain::draw()
{
	player.init();
	player.draw();
	DrawString(0, 0, "ƒƒCƒ“‰æ–Ê", GetColor(255, 255, 255));
}