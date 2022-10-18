#include"DxLib.h"
#include "SceneMain.h"
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
}

SceneMain::SceneMain()
{
	m_isEnd = false;

	basePosX = 0;
	basePosY = 0;
	baseDownX = 0;
	baseDownY = 0;
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

	if (m_enemy.isDead() == true)
	{
		DrawString(0, 0, "�N���A�ł��BB�{�^�� or X key �������Ă��������B", GetColor(255, 255, 255));
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
		basePosX = pShot->getPos().x;
		basePosY = pShot->getPos().y;
		baseDownX = pShot->getBottomRight().x;
		baseDownY = pShot->getBottomRight().y;
	}

		//���ݑ��݂��Ă���ʂ̐���\��
		DrawFormatString(500, 5, GetColor(0, 255, 255), "�e�̐�:%d", m_pShotVt.size());


		//if (isCol() == true)
		if (isCol() == false)
		{
			DrawString(0, 500, "�������ĂȂ�", GetColor(255, 255, 255));
		}
		else
			//if (isCol() == false)
		{
			DrawString(0, 550, "��������", GetColor(255, 255, 255));
		}

		//�f�o�b�O�̂��߂̕\��
		//DrawBox(basePosX, basePosX, baseDownX, baseDownY, GetColor(255, 255, 255), false);
		//DrawBox(m_enemy.getPos().x , m_enemy.getPos().y , m_enemy.getBottomRight().x, m_enemy.getBottomRight().y, GetColor(255, 255, 255), false);
		DrawBox(m_enemy.getPos().x - 5, m_enemy.getPos().y - 5, m_enemy.getBottomRight().x + 5, m_enemy.getBottomRight().y + 5, GetColor(0, 255, 0), false);		//�`�F�b�N�p
		DrawFormatString(0, 650, GetColor(0, 255, 255), "�G���W:%f %f", m_enemy.getPos().x, m_enemy.getPos().y);
		//DrawFormatString(0, 700, GetColor(0, 255, 0), "�e���W:%f %f", pShot->getPos().x, pShot->getPos().y);
		DrawFormatString(0, 600, GetColor(0, 255, 0), "�����W:%f %f", m_player.getPos().x, m_player.getPos().y);
	
		DrawFormatString(500, 400, GetColor(0, 255, 255), "���W:%f %f", basePosX, basePosY);
		
		if (isCol())			//���S���Ă��邩�`�F�b�N
		{
			m_enemy.Dead();
		}
		else
		{

		}

		if (m_enemy.isDead() == true)
		{
			//�f�o�b�O�p
			DrawString(0, 20, "���S", GetColor(255, 255, 255));
		}
		else
		{
			//�f�o�b�O�p
			DrawString(0, 20, "����", GetColor(255, 255, 255));
		}
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

	if (basePosX > m_enemy.getBottomRight().x)return false;
	if (baseDownX < m_enemy.getPos().x)return false;
	if (basePosY > m_enemy.getBottomRight().y)return false;
	if (baseDownY < m_enemy.getPos().y)return false;

	return true;
}