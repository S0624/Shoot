#include"game.h"
#include"ShotPlayer.h"

namespace
{
	constexpr float kShotSpeed = 4.0f;
}

void ShotPlayer::start(Vec2 pos)
{
	ShotBase::start(pos);
	m_vec.y -= kShotSpeed;
}

void ShotPlayer::update()
{
	if (!m_isExist)return;
	m_pos += m_vec;

	if (m_pos.y < 0)
	{
		m_isExist = false;
	}
}