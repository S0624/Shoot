#include"game.h"
#include"ShotEnemy.h"

namespace
{
	constexpr float kShotSpeed = 8.0f;
}

void ShotEnemy::start(Vec2 pos)
{
	ShotBase::start(pos);
	m_vec.y += kShotSpeed;
}

void ShotEnemy::update()
{
	if (!m_isExist)return;
	m_pos += m_vec;

	if (m_pos.y < 0)
	{
		m_isExist = false;
	}
}