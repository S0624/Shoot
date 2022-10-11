#include"DxLib.h"
#include"game.h"
#include "Player.h"


namespace
{
	constexpr int kpos_y = 660;			//プレイヤー縦の大きさ
	constexpr int kSpeed = 5;			//プレイヤーの移動速度
}

Player::Player()
{
	m_pos.x = 620;
	m_vec = 0;
	m_size.x = 40;
}

Player:: ~Player()
{

}

void Player::init()
{
	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

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

void Player::update()
{

}

void Player::draw()
{
	DrawBox(m_pos.x, kpos_y, m_pos.x + m_size.x, kpos_y + m_size.x, GetColor(255, 255, 255), false);
}