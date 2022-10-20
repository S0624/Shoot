#include"DxLib.h"
#include"game.h"
#include"Enemy.h"

#include "SceneMain.h"

namespace
{
	constexpr int kShotInterval = 20;		//ショットの発射間隔
	constexpr float kRadius = 20.0;		//ショットの発射間隔
}

Enemy::Enemy()
{
	m_pMain = nullptr;
	m_isDead = false;
	m_shotInterval = 5;			//ショットの発射間隔
}

void Enemy::init()
{
	m_pos.y = 10;
	m_vec.x = 2.5f;

	m_size.x = 40;
	m_size.y = 40;
}

void Enemy::setPos(int posX)
{
	m_pos.x = posX;//620;
}

void Enemy::update()
{
	//int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	////ショット処理
	//m_shotInterval--;
	//if (m_shotInterval < 0)m_shotInterval = 0;

	//if (m_shotInterval <= 0)
	//{
	//	if (padState & PAD_INPUT_2)
	//	{
	//		if (m_pMain->createShotEnemy(getPos()))
	//		{
	//			m_shotInterval = kShotInterval;
	//		}
	//	}
	//}
	m_pos.x += m_vec.x;										//エネミーの移動

	if (m_pos.x < 0.0f)										//画面外に行かないように設定
	{
		m_pos.x = 0;
		m_vec.x *= -1.0f;
	}

	if (m_pos.x > Game::kScreenWindth - m_size.x)			//画面外に行かないように設定
	{
		m_pos.x = Game::kScreenWindth - m_size.x;
		m_vec.x *= -1.0f;
	}
}

void Enemy::draw()
{
	if (m_isDead) return;
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.x, GetColor(255, 0, 0), false);				//描画
}

void Enemy::end()
{
	DeleteGraph(DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.x, GetColor(255, 0, 0), false));
}