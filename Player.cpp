#include"DxLib.h"
#include"game.h"
#include "Player.h"

#include "SceneMain.h"

namespace
{
	constexpr float kSpeed = 1.5f;			//プレイヤーの移動速度
	constexpr float kSpeedMax = 10.5f;		//プレイヤーの最大移動速度

	constexpr int kShotInterval = 10;		//ショットの発射間隔
}

Player::Player()
{
	m_pMain = nullptr;
	m_shotInterval = 5;
}

void Player::init()
{
	m_pos.x = 620.f;
	m_pos.y = 660.f;
	m_vec.x = 0.0f;
	m_size.x = 40;
}

void Player::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (m_enemy.isDead() == false)		//エネミーが死亡したらクリア
	{ 									//ショット処理
		m_shotInterval--;
		if (m_shotInterval < 0)
		{
			m_shotInterval = 0;
		}

		if (m_shotInterval <= 0)
		{
			if (padState & PAD_INPUT_1)
			{
				if (m_pMain->createShotPlayer(getPos() + m_size / 2))
				{
					m_shotInterval = kShotInterval;
				}
			}
		}

		if (padState & PAD_INPUT_LEFT)				//左に移動する
		{
			m_vec.x -= kSpeed;
			if (m_vec.x < -kSpeedMax)	m_vec.x = -kSpeedMax;
		}
		if (padState & PAD_INPUT_RIGHT)				//右に移動する
		{
			m_vec.x += kSpeed;
			if (m_vec.x > kSpeedMax)	m_vec.x = kSpeedMax;
		}
		else
		{
			m_vec.x *= 0.9f;
		}

		m_pos += m_vec;

		if (m_pos.x < 0)										//画面外に行かないように設定
		{
			m_pos.x = 0;
			m_vec.x = 0;
		}
		if (m_pos.x > Game::kScreenWindth - m_size.x)			//画面外に行かないように設定
		{
			m_pos.x = Game::kScreenWindth - m_size.x;
			m_vec.x = 0;
		}
	}
}

void Player::draw()
{
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.x, GetColor(0, 255, 255), false);					//描画
}

void Player::end()
{
	DeleteGraph(DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.x, GetColor(0, 255, 255), false));
}