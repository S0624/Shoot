#include"DxLib.h"
#include"game.h"
#include "Player.h"

#include "SceneMain.h"

namespace
{
	constexpr float kSpeed = 5.0f;			//�v���C���[�̈ړ����x

	constexpr int kShotInterval = 16;		//�V���b�g�̔��ˊԊu
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

	////�V���b�g����
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

	if (padState & PAD_INPUT_LEFT)				//���Ɉړ�����
	{
		m_pos.x -= kSpeed;
	}
	if (padState & PAD_INPUT_RIGHT)				//�E�Ɉړ�����
	{
		m_pos.x += kSpeed;
	}

	if (m_pos.x > Game::kScreenWindth - m_size.x)			//��ʊO�ɍs���Ȃ��悤�ɐݒ�
	{
		m_pos.x = Game::kScreenWindth - m_size.x;
	}

	if (m_pos.x < 0)										//��ʊO�ɍs���Ȃ��悤�ɐݒ�
	{
		m_pos.x = 0;
	}
}

void Player::draw()
{
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.x, GetColor(255, 255, 255), false);
}