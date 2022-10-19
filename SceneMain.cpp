#include"DxLib.h"
#include"SceneMain.h"
#include"SceneResult.h"
#include"ShotBase.h"
#include"ShotPlayer.h"
#include"ShotEnemy.h"
#include<cassert>

namespace
{
	int kPosX = 0;						//敵の場所をずらす為の変数
	constexpr int kEnemyNum = 6;		//敵の数
	bool kCheck = false;				//死亡判定を渡すための変数
	
	Enemy m_enemy[kEnemyNum];			//敵の配列
}

SceneMain::SceneMain()
{
	m_isEnd = false;					//初期化
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
		assert(pShot);				//バグがあったらわざと止める処理
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

		int enemuNum = kEnemyNum;			//敵の生存数
		for (int i = 0; i < kEnemyNum; i++)
		{
			if (m_enemy[i].isDead() == true)
			{
				enemuNum -= 1;				//敵に当たったら数を一つ減らす
			}
		}

		if (enemuNum == 0)		//エネミーが全部死亡したらクリア
		{
			DrawString(520, 380, "クリアです。Bボタン or X key を押してください。", GetColor(255, 255, 255));
			int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
			if (padState & PAD_INPUT_2)
			{
				m_isEnd = true;						//Bボタンを押したらリザルトにシーンを切り替える
			}
		}

		std::vector<ShotBase*>::iterator it = m_pShotVt.begin();
		while (it != m_pShotVt.end())
		{
			auto& pShot = (*it);

			assert(pShot);				//バグがあったらわざと止める処理
			pShot->update();

			if (pShot->getPos().x > enemy.getBottomRight().x ||				//shotと敵の当たり判定
				pShot->getBottomRight().x < enemy.getPos().x ||
				pShot->getPos().y > enemy.getBottomRight().y ||
				pShot->getBottomRight().y < enemy.getPos().y)
			{
				kCheck = false;												//当たっていなかったらfalseを返す
			}
			else
			{
				/*DrawFormatString(0, 0, GetColor(0, 255, 255), "当たってる");*/
				kCheck = true;												//当たっていたらtrueを返す
			}

			if (isCol() == true)			//死亡しているかチェック
			{
				enemy.Dead();				//死亡していたらDeadにtrueをいれる
			}


			//if (m_enemy.isDead() == true);
			//else {}

			/*if (isCol() == false);
			else {}*/

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
}

void SceneMain::draw()
{
	m_player.draw();						//描画

	for (auto& enemy : m_enemy)
	{
		enemy.draw();
	}

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
	//for (int i = 0; i < kCheck; i++)
	//{
	//	if (m_enemy[i].isDead()) return false;				//エネミーが死亡していたら当たらない
	//}

	if (kCheck == false)			//kCeckにfalseが入っていたらfalseを返す
	{
		return false;
	}
	else							//kCeckにtrueが入っていたらtrueを返す
	{
		return true;
	}
}