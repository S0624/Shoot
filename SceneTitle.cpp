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
		m_isEnd = true;					//main�ɐ؂�ւ�
	}
}

void SceneTitle::draw()
{
	DrawString(620, 380, "�^�C�g�����", GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��
	DrawString(620, 480, "Y or KEY A�{�^��", GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��
	
	DrawBox(0, 0, 25, 25, GetColor(255,255,255), false);    // �l�p�`��`��
}