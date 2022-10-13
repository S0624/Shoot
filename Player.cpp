#include"DxLib.h"
#include"game.h"
#include "Player.h"

#include "SceneMain.h"

namespace
{
	constexpr float kSpeed = 5.0f;			//プレイヤーの移動速度

	constexpr int kShotInterval = 16;		//ショットの発射間隔
}

Player::Player()
{
	m_pMain = nullptr;
	m_shotInterval = 0;
}

void Player::init()
{
	m_pos.x = 620;
	m_pos.y = 660;
	m_vec.x = 0.0f;
	m_size.x = 40;
}

void Player::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	////ショット処理
	//m_shotInterval--;
	//if (m_shotInterval < 0)m_shotInterval = 0;

	//if (m_shotInterval <= 0)
	//{
	//	if (padState & PAD_INPUT_2)
	//	{
	//		if (m_pMain->createShotPlayer(getPos()))
	//		{
	//			m_shotInterval = kShotInterval;
	//		}
	//	}
	//}

	if (padState & PAD_INPUT_LEFT)				//左に移動する
	{
		m_pos.x -= kSpeed;
	}
	if (padState & PAD_INPUT_RIGHT)				//右に移動する
	{
		m_pos.x += kSpeed;
	}

	if (m_pos.x > Game::kScreenWindth - m_size.x)			//画面外に行かないように設定
	{
		m_pos.x = Game::kScreenWindth - m_size.x;
	}

	if (m_pos.x < 0)										//画面外に行かないように設定
	{
		m_pos.x = 0;
	}
}

void Player::draw()
{
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.x, GetColor(255, 255, 255), false);
}