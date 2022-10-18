#include"DxLib.h"
#include "SceneMain.h"
#include"SceneResult.h"
#include"ShotBase.h"
#include"ShotPlayer.h"
#include"ShotEnemy.h"
#include<cassert>


namespace
{
	//ショットの発射間隔
	constexpr int kShotInterval = 16;
	constexpr int kEnemyNum = 3;		//敵の数
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
		assert(pShot);				//バグがあったらわざと止める処理
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
		DrawString(0, 0, "クリアです。Bボタン or X key を押してください。", GetColor(255, 255, 255));
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

		assert(pShot);				//バグがあったらわざと止める処理
		pShot->update();
		if (!pShot->isExsist())
		{
			delete pShot;
			pShot = nullptr;

			//vectorの要素削除
			it = m_pShotVt.erase(it);		//指定した場所を削除する
			continue;					//削除したときループの先頭に戻る
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

		//現在存在している玉の数を表示
		DrawFormatString(500, 5, GetColor(0, 255, 255), "弾の数:%d", m_pShotVt.size());


		//if (isCol() == true)
		if (isCol() == false)
		{
			DrawString(0, 500, "当たってない", GetColor(255, 255, 255));
		}
		else
			//if (isCol() == false)
		{
			DrawString(0, 550, "当たった", GetColor(255, 255, 255));
		}

		//デバッグのための表示
		//DrawBox(basePosX, basePosX, baseDownX, baseDownY, GetColor(255, 255, 255), false);
		//DrawBox(m_enemy.getPos().x , m_enemy.getPos().y , m_enemy.getBottomRight().x, m_enemy.getBottomRight().y, GetColor(255, 255, 255), false);
		DrawBox(m_enemy.getPos().x - 5, m_enemy.getPos().y - 5, m_enemy.getBottomRight().x + 5, m_enemy.getBottomRight().y + 5, GetColor(0, 255, 0), false);		//チェック用
		DrawFormatString(0, 650, GetColor(0, 255, 255), "敵座標:%f %f", m_enemy.getPos().x, m_enemy.getPos().y);
		//DrawFormatString(0, 700, GetColor(0, 255, 0), "弾座標:%f %f", pShot->getPos().x, pShot->getPos().y);
		DrawFormatString(0, 600, GetColor(0, 255, 0), "自座標:%f %f", m_player.getPos().x, m_player.getPos().y);
	
		DrawFormatString(500, 400, GetColor(0, 255, 255), "座標:%f %f", basePosX, basePosY);
		
		if (isCol())			//死亡しているかチェック
		{
			m_enemy.Dead();
		}
		else
		{

		}

		if (m_enemy.isDead() == true)
		{
			//デバッグ用
			DrawString(0, 20, "死亡", GetColor(255, 255, 255));
		}
		else
		{
			//デバッグ用
			DrawString(0, 20, "生存", GetColor(255, 255, 255));
		}
}

bool SceneMain::createShotPlayer(Vec2 pos)
{
	ShotPlayer* pShot = new ShotPlayer;
	pShot->start(pos);
	m_pShotVt.push_back(pShot);

	return true;
}


bool SceneMain::isCol()				//当たり判定
{
	if (m_enemy.isDead()) return false;

	if (basePosX > m_enemy.getBottomRight().x)return false;
	if (baseDownX < m_enemy.getPos().x)return false;
	if (basePosY > m_enemy.getBottomRight().y)return false;
	if (baseDownY < m_enemy.getPos().y)return false;

	return true;
}