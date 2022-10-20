#include"DxLib.h"
#include"SceneMain.h"
#include"SceneResultLose.h"
#include"ShotBase.h"
#include"ShotPlayer.h"
#include"ShotEnemy.h"
#include<cassert>

namespace
{
	constexpr int kEnemyNum = 6;		//敵の数
	Enemy m_enemy[kEnemyNum];			//敵の配列
	int kPosX = 0;						//敵の場所をずらす為の変数
	bool kCheck = false;				//死亡判定を渡すための変数
	constexpr int kShotRemaining = 20;			//ショットの残り
}

SceneMain::SceneMain()
{
	m_enemyNum = 0;
	shotNumCount = 0;
	shotCountDown = 0;
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

		int enemyNum = kEnemyNum;			//敵の生存数
		for (int i = 0; i < kEnemyNum; i++)
		{
			if (m_enemy[i].isDead() == true)
			{
				enemyNum -= 1;				//敵に当たったら数を一つ減らす
			}
		}
		//DrawFormatString(0, 0, GetColor(0, 255, 255), "弾の数:%d", m_enemyNum);
		m_enemyNum = enemyNum;


		if (survivalNum() == 0 || shotCountDown <= 0)		//エネミーが全部死亡したらクリアまたはShotの残数が0になったらゲームオーバー
		{
			int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
			if (shotCountDown <= 0)
			{
				DrawString(520, 380, "弾の残数が切れました。Bボタン or X key を押してください。", GetColor(255, 255, 255));
				if (padState & PAD_INPUT_2)
				{
					m_isEnd = true;						//Bボタンを押したらリザルトにシーンを切り替える
				}
			}
			else if (survivalNum() == 0)
			{
				DrawString(520, 380, "クリアです。Xボタン or C key を押してください。", GetColor(255, 255, 255));
				if (padState & PAD_INPUT_3)
				{
					DxLib_End();				//ボタンが押されたらゲームを終了する
				}
			}
		}

		std::vector<ShotBase*>::iterator it = m_pShotVt.begin();
		while (it != m_pShotVt.end())
		{
			auto& pShot = (*it);

			assert(pShot);				//バグがあったらわざと止める処理
			pShot->update();

			//if (enemy.isDead())	continue;									//エネミーが死亡していたら当たらない

			if (pShot->getPos().x > enemy.getBottomRight().x ||				//shotと敵の当たり判定
				pShot->getBottomRight().x < enemy.getPos().x ||
				pShot->getPos().y > enemy.getBottomRight().y ||
				pShot->getBottomRight().y < enemy.getPos().y)
			{
				kCheck = false;												//当たっていなかったらfalseを返す
			}
			else
			{
				kCheck = true;												//当たっていたらtrueを返す
			}

			if (isCol() == true)			//死亡しているかチェック
			{
				enemy.Dead();				//死亡していたらDeadにtrueをいれる
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

	shotNumCount = 0;
	shotCountDown = kShotRemaining;

	for (auto& pShot : m_pShotVt)
	{
		if (!pShot) continue;
		pShot->draw();
		shotNumCount++;
	}
	shotCountDown -= shotNumCount;

	DrawFormatString(0, 325, GetColor(0, 255, 255), "弾の撃った数:%d", shotNumCount);


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

	if (kCheck == false)			//kCeckにfalseが入っていたらfalseを返す
	{
		return false;
	}
	else							//kCeckにtrueが入っていたらtrueを返す
	{
		return true;
	}
}