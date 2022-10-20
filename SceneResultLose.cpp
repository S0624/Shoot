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
		DxLib_End();				//�{�^���������ꂽ��Q�[�����I������
	}
}

void SceneResultLose::draw()
{
	DrawString(600, 200, "���U���g", GetColor(255, 255, 255));			//���U���g��ʂ̕\��
	DrawString(600, 500, "X�{�^�� or C key", GetColor(255, 255, 255));			//�����{�^���̕\����ʂ̕\��
	DrawString(600, 450, "���ׂĂ̓G�����Ă܂���ł����B", GetColor(255, 255, 255));			//���ʂ̕\��	
}