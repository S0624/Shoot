#include"DxLib.h"
#include"game.h"
#include "Player.h"

#include "SceneMain.h"

namespace
{
	constexpr float kSpeed = 1.5f;			//�v���C���[�̈ړ����x
	constexpr float kSpeedMax = 10.5f;		//�v���C���[�̍ő�ړ����x

	constexpr int kShotInterval = 10;		//�V���b�g�̔��ˊԊu
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

	if (m_enemy.isDead() == false)		//�G�l�~�[�����S������N���A
	{ 									//�V���b�g����
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

		if (padState & PAD_INPUT_LEFT)				//���Ɉړ�����
		{
			m_vec.x -= kSpeed;
			if (m_vec.x < -kSpeedMax)	m_vec.x = -kSpeedMax;
		}
		if (padState & PAD_INPUT_RIGHT)				//�E�Ɉړ�����
		{
			m_vec.x += kSpeed;
			if (m_vec.x > kSpeedMax)	m_vec.x = kSpeedMax;
		}
		else
		{
			m_vec.x *= 0.9f;
		}

		m_pos += m_vec;

		if (m_pos.x < 0)										//��ʊO�ɍs���Ȃ��悤�ɐݒ�
		{
			m_pos.x = 0;
			m_vec.x = 0;
		}
		if (m_pos.x > Game::kScreenWindth - m_size.x)			//��ʊO�ɍs���Ȃ��悤�ɐݒ�
		{
			m_pos.x = Game::kScreenWindth - m_size.x;
			m_vec.x = 0;
		}
	}
}

void Player::draw()
{
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.x, GetColor(0, 255, 255), false);					//�`��
}

void Player::end()
{
	DeleteGraph(DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.x, GetColor(0, 255, 255), false));
}