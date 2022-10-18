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
		//�^�C�g���ɐ؂�ւ�
		m_isEnd = true;
	}
}

void SceneResult::draw()
{
	DrawString(620, 380, "���U���g���", GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��
	DrawString(620, 480, "B�{�^��", GetColor(255, 255, 255));			//�^�C�g����ʂ̕\��

	DrawBox(0, 0, 25, 25, GetColor(255, 255, 255), false);    // �l�p�`��`��
}