#include"DxLib.h"
#include "SceneMain.h"
#include"SceneTitle.h"
#include"ShotPlayer.h"
#include"ShotEnemy.h"
#include<cassert>


namespace
{
	//�V���b�g�̔��ˊԊu
	constexpr int kShotInterval = 16;
}

SceneMain::SceneMain()
{
	m_isEnd = false;
}

void SceneMain::init()
{
	m_player.init();
	m_player.setMain(this);

	m_enemy.init();
	m_enemy.setMain(this);
}

void SceneMain::end()
{
	for (auto& pShot : m_pShotVt)
	{
		assert(pShot);				//�o�O����������킴�Ǝ~�߂鏈��
		delete pShot;
		pShot = nullptr;
	}
}

void SceneMain::update()
{
	m_player.update();
	m_enemy.update();

	/*int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_2)
	{
		m_isEnd = true;
	}*/

	std::vector<ShotBase*>::iterator it = m_pShotVt.begin();
	while (it != m_pShotVt.end())
	{
		auto& pShot = (*it);

		assert(pShot);				//�o�O����������킴�Ǝ~�߂鏈��
		pShot->update();
		if (!pShot->isExsist())
		{
			delete pShot;
			pShot = nullptr;

			//vector�̗v�f�폜
			it = m_pShotVt.erase(it);		//�w�肵���ꏊ���폜����
			continue;					//�폜�����Ƃ����[�v�̐擪�ɖ߂�
		}
		it++;
	}
}


void SceneMain::draw()
{
	m_player.draw();
	m_enemy.draw();
	
	for (auto& pShot : m_pShotVt)
	{
		if (!pShot) continue;
		pShot->draw();
	}
	DrawString(0, 0, "���C�����", GetColor(255, 255, 255));

	//���ݑ��݂��Ă���ʂ̐���\��
	DrawFormatString(100, 0, GetColor(0, 255, 255), "�e�̐�:%d", m_pShotVt.size());

	if (isCol() == false)
	{
		DrawString(0, 500, "��������", GetColor(255, 255, 255));
	}
	if (isCol() == true)
	{
		DrawString(0, 600, "�������ĂȂ�", GetColor(255, 255, 255));
	}
	
	DrawFormatString(0, 650, GetColor(0, 255, 255), "�G���W:%f %f", m_enemy.getPos().x, m_enemy.getPos().y);
	DrawFormatString(0, 700, GetColor(0, 255, 0), "�e���W:%f %f", m_base.getPos().x, m_base.getPos().y);

}

bool SceneMain::createShotPlayer(Vec2 pos)
{
	ShotPlayer* pShot = new ShotPlayer;
	pShot->start(pos);
	m_pShotVt.push_back(pShot);

	return true;
}


bool SceneMain::isCol()
{	
	if (m_base.getPos().x > m_enemy.getPos().x)return false;
	//if (m_base.getBottomRight().x < m_enemy.getPos().x)return false;
	if (m_base.getPos().y > m_enemy.getPos().y)return false;
	//if (m_base.getBottomRight().y < m_enemy.getPos().y)return false;

	return true;
}