#include"DxLib.h"
#include"SceneMain.h"
#include"SceneResult.h"
#include"ShotBase.h"
#include"ShotPlayer.h"
#include"ShotEnemy.h"
#include<cassert>

namespace
{
	int kPosX = 0;						//�G�̏ꏊ�����炷�ׂ̕ϐ�
	constexpr int kEnemyNum = 5;		//�G�̐�
	bool kCheck = false;		//���S�����n�����߂̕ϐ�
	
	Enemy m_enemy[kEnemyNum];
	Enemy m_penemy;



	//////////////////////
	//int u = 200;
	
}

SceneMain::SceneMain()
{
	m_isEnd = false;
}

void SceneMain::init()
{
	m_player.init();
	m_player.setMain(this);

	for (auto& enemy : m_enemy)
	{
		kPosX += 200;
		enemy.init();
		enemy.setMain(this);
		enemy.setPos(kPosX);
	}
}

void SceneMain::end()
{
	m_player.end();
	for (auto& enemy : m_enemy)
	{
		enemy.end();
	}

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
	for (auto& enemy : m_enemy)
	{
		enemy.update();

		int enemuNum = kEnemyNum;
		for (int i = 0; i < kEnemyNum; i++)
		{
			if (m_enemy[i].isDead() == true)
			{
				enemuNum -= 1;
			}
		}

		if (enemuNum == 0)		//�G�l�~�[���S�����S������N���A
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

			if (pShot->getPos().x > enemy.getBottomRight().x ||
				pShot->getBottomRight().x < enemy.getPos().x ||
				pShot->getPos().y > enemy.getBottomRight().y ||
				pShot->getBottomRight().y < enemy.getPos().y)
			{
				kCheck = false;
			}
			else
			{
				/*DrawFormatString(0, 0, GetColor(0, 255, 255), "�������Ă�");*/
				kCheck = true;
			}

			if (isCol() == true)			//���S���Ă��邩�`�F�b�N
			{
				enemy.Dead();				//���S���Ă�����Dead��true�������
			}
			else {}


			//if (m_enemy.isDead() == true);
			//else {}

			/*if (isCol() == false);
			else {}*/

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
}

void SceneMain::draw()
{
	m_player.draw();

	for (auto& enemy : m_enemy)
	{
		enemy.draw();
	}

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
	//for (int i = 0; i < kCheck; i++)
	//{
	//	if (m_enemy[i].isDead()) return false;				//�G�l�~�[�����S���Ă����瓖����Ȃ�
	//}

	if (kCheck == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}