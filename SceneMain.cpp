#include"DxLib.h"
#include "SceneMain.h"
#include"SceneTitle.h"
#include"ShotPlayer.h"
#include<cassert>


namespace
{
	//ショットの発射間隔
	constexpr int kShotInterval = 16;
}

SceneMain::SceneMain()
{
	m_isEnd = false;
}

void SceneMain::init()
{
	m_player.init();
	m_enemy.init();
}

void SceneMain::end()
{
	//m_player.end();
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

	/*int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_2)
	{
		m_isEnd = true;
	}*/

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
	}
	DrawString(0, 0, "メイン画面", GetColor(255, 255, 255));
}

bool SceneMain::createShotPlayer(Vec2 pos)
{
	ShotPlayer* pShot = new ShotPlayer;
	pShot->start(pos);
	m_pShotVt.push_back(pShot);

	return true;
}