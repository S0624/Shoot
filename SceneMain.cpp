#include"DxLib.h"
#include"SceneMain.h"
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
	bool kCheck = false;		//敵の数
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
		assert(pShot);				//バグがあったらわざと止める処理
		delete pShot;
		pShot = nullptr;
	}
}

void SceneMain::update()
{
	m_player.update();
	m_enemy.update();

	if (m_enemy.isDead() == true)		//エネミーが死亡したらクリア
	{
		DrawString(520, 380, "クリアです。Bボタン or X key を押してください。", GetColor(255, 255, 255));
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

		if (isCol() == true)			//死亡しているかチェック
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
	}
		//現在存在している玉の数を表示
		DrawFormatString(0, 25, GetColor(0, 255, 255), "弾の数:%d", m_pShotVt.size());
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
	if (kCheck == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}