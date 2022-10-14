#include"DxLib.h"
#include"game.h"
#include"Enemy.h"

#include "SceneMain.h"

namespace
{
	constexpr int kShotInterval = 20;		//�V���b�g�̔��ˊԊu
	constexpr float kRadius = 20.0;		//�V���b�g�̔��ˊԊu
}

Enemy::Enemy()
{
	m_pMain = nullptr;
	m_shotInterval = 0;
}

void Enemy::init()
{
	m_pos.x = 620;
	m_pos.y = 10;
	m_vec.x = 2.5f;
	m_size.x = 40;
}

void Enemy::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//�V���b�g����
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

	m_pos.x += m_vec.x;										//�G�l�~�[�̈ړ�

	if (m_pos.x < 0.0f)										//��ʊO�ɍs���Ȃ��悤�ɐݒ�
	{
		m_pos.x = 0;
		m_vec.x *= -1.0f;
	}

	if (m_pos.x > Game::kScreenWindth - m_size.x)			//��ʊO�ɍs���Ȃ��悤�ɐݒ�
	{
		m_pos.x = Game::kScreenWindth - m_size.x;
		m_vec.x *= -1.0f;
	}

}

void Enemy::draw()
{
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.x, GetColor(255, 0, 0), false);
	DrawCircle(getCenter().x, getCenter().y, getRadius(), GetColor(0, 0, 255), false);
}
float Enemy::getRadius()const
{
	return kRadius;
}
Vec2 Enemy::getCenter()const
{
	int sizeX = 0;
	int sizeY = 0;

	Vec2 result = m_pos;
	result.x -= m_pos.x * 2;
	result.y -= m_pos.y * 2;

	return result;
}