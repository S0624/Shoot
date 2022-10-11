#include"DxLib.h"
#include"game.h"
#include "Player.h"


namespace
{
	constexpr int kpos_y = 660;			//�v���C���[�c�̑傫��
	constexpr int kSpeed = 5;			//�v���C���[�̈ړ����x
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
	// �p�b�h(�������̓L�[�{�[�h)����̓��͂��擾����
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

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

void Player::update()
{

}

void Player::draw()
{
	DrawBox(m_pos.x, kpos_y, m_pos.x + m_size.x, kpos_y + m_size.x, GetColor(255, 255, 255), false);
}