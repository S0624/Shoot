#include"DxLib.h"
#include"SceneMain.h"
#include"SceneResult.h"
#include"ShotBase.h"
#include"ShotPlayer.h"
#include"ShotEnemy.h"
#include<cassert>


namespace
{
	//�V���b�g�̔��ˊԊu
	constexpr int kShotInterval = 16;
	constexpr int kEnemyNum = 3;		//�G�̐�
	bool kCheck = false;		//�G�̐�
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

	if (m_enemy.isDead() == true)		//�G�l�~�[�����S������N���A
	{
		DrawString(520, 380, "�N���A�ł��BB�{�^�� or X key �������Ă��������B", GetColor(255, 255, 255));
		int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if (padState & PAD_INPUT_2)
		{
			m_isEnd = true;
		}
	}

	std::vector<ShotBase*>::iterator it = m_pShotVt.begin();
	while (it != m_pShotVt.end())
	{
		auto& pShot = (*it);

		assert(pShot);				//�o�O����������킴�Ǝ~�߂鏈��
		pShot->update();

		if (pShot->getPos().x > m_enemy.getBottomRight().x||
			pShot->getBottomRight().x < m_enemy.getPos().x||
			pShot->getPos().y > m_enemy.getBottomRight().y||
			pShot->getBottomRight().y < m_enemy.getPos().y)
		{
			kCheck = false;
		}
		else
		{
			kCheck = true;
		}

		if (isCol() == true)			//���S���Ă��邩�`�F�b�N
		{
			m_enemy.Dead();
		}
		else {}

		if (m_enemy.isDead() == true);
		else {}

		if (isCol() == false);
		else {}

		
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
		//���ݑ��݂��Ă���ʂ̐���\��
		DrawFormatString(0, 25, GetColor(0, 255, 255), "�e�̐�:%d", m_pShotVt.size());
}

bool SceneMain::createShotPlayer(Vec2 pos)
{
	ShotPlayer* pShot = new ShotPlayer;
	pShot->start(pos);
	m_pShotVt.push_back(pShot);

	return true;
}


bool SceneMain::isCol()				//�����蔻��
{
	if (m_enemy.isDead()) return false;
	if (kCheck == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}