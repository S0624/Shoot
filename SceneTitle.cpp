#include"DxLib.h"
#include "SceneTitle.h"
#include "SceneMain.h"

SceneTitle::SceneTitle()
{
	m_isEnd = false;
}

SceneBase* SceneTitle::update()
{

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
		//main�ɐ؂�ւ�
		return(new SceneMain);
	}
	return this;

}

void SceneTitle::draw()
{
	DrawString(620, 380, "�^�C�g�����", GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��
	
	DrawBox(0, 0, 25, 25, GetColor(255,255,255), false);    // �l�p�`��`��
}