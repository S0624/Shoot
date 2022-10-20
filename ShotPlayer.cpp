#include"game.h"
#include"ShotPlayer.h"

namespace
{
	constexpr float kShotSpeed = 4.0f;		//�e�̃X�s�[�h�̎w��
}

void ShotPlayer::start(Vec2 pos)
{
	ShotBase::start(pos);
	m_vec.y -= kShotSpeed;					//�e���o������̎w��
}

void ShotPlayer::update()
{
	m_pos += m_vec;

	if (m_pos.y < 0)
	{
		m_isExist = false;
	}
}