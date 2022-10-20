#include"DxLib.h"
#include"SceneMain.h"
#include"SceneResultLose.h"
#include"ShotBase.h"
#include"ShotPlayer.h"
#include"ShotEnemy.h"
#include<cassert>

namespace
{
	constexpr int kEnemyNum = 6;		//�G�̐�
	Enemy m_enemy[kEnemyNum];			//�G�̔z��
	int kPosX = 0;						//�G�̏ꏊ�����炷�ׂ̕ϐ�
	bool kCheck = false;				//���S�����n�����߂̕ϐ�
	constexpr int kShotRemaining = 20;			//�V���b�g�̎c��
}

SceneMain::SceneMain()
{
	m_enemyNum = 0;
	shotNumCount = 0;
	shotCountDown = 0;
	m_isEnd = false;					//������
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

		int enemyNum = kEnemyNum;			//�G�̐�����
		for (int i = 0; i < kEnemyNum; i++)
		{
			if (m_enemy[i].isDead() == true)
			{
				enemyNum -= 1;				//�G�ɓ��������琔������炷
			}
		}
		//DrawFormatString(0, 0, GetColor(0, 255, 255), "�e�̐�:%d", m_enemyNum);
		m_enemyNum = enemyNum;


		if (survivalNum() == 0 || shotCountDown <= 0)		//�G�l�~�[���S�����S������N���A�܂���Shot�̎c����0�ɂȂ�����Q�[���I�[�o�[
		{
			int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
			if (shotCountDown <= 0)
			{
				DrawString(520, 380, "�e�̎c�����؂�܂����BB�{�^�� or X key �������Ă��������B", GetColor(255, 255, 255));
				if (padState & PAD_INPUT_2)
				{
					m_isEnd = true;						//B�{�^�����������烊�U���g�ɃV�[����؂�ւ���
				}
			}
			else if (survivalNum() == 0)
			{
				DrawString(520, 380, "�N���A�ł��BX�{�^�� or C key �������Ă��������B", GetColor(255, 255, 255));
				if (padState & PAD_INPUT_3)
				{
					DxLib_End();				//�{�^���������ꂽ��Q�[�����I������
				}
			}
		}

		std::vector<ShotBase*>::iterator it = m_pShotVt.begin();
		while (it != m_pShotVt.end())
		{
			auto& pShot = (*it);

			assert(pShot);				//�o�O����������킴�Ǝ~�߂鏈��
			pShot->update();

			//if (enemy.isDead())	continue;									//�G�l�~�[�����S���Ă����瓖����Ȃ�

			if (pShot->getPos().x > enemy.getBottomRight().x ||				//shot�ƓG�̓����蔻��
				pShot->getBottomRight().x < enemy.getPos().x ||
				pShot->getPos().y > enemy.getBottomRight().y ||
				pShot->getBottomRight().y < enemy.getPos().y)
			{
				kCheck = false;												//�������Ă��Ȃ�������false��Ԃ�
			}
			else
			{
				kCheck = true;												//�������Ă�����true��Ԃ�
			}

			if (isCol() == true)			//���S���Ă��邩�`�F�b�N
			{
				enemy.Dead();				//���S���Ă�����Dead��true�������
			}
			it++;
		}
	}
}

void SceneMain::draw()
{
	m_player.draw();						//�`��

	for (auto& enemy : m_enemy)
	{
		enemy.draw();
	}

	shotNumCount = 0;
	shotCountDown = kShotRemaining;

	for (auto& pShot : m_pShotVt)
	{
		if (!pShot) continue;
		pShot->draw();
		shotNumCount++;
	}
	shotCountDown -= shotNumCount;

	DrawFormatString(0, 325, GetColor(0, 255, 255), "�e�̌�������:%d", shotNumCount);


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

	if (kCheck == false)			//kCeck��false�������Ă�����false��Ԃ�
	{
		return false;
	}
	else							//kCeck��true�������Ă�����true��Ԃ�
	{
		return true;
	}
}