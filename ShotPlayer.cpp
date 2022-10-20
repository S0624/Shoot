#include"game.h"
#include"ShotPlayer.h"

namespace
{
	constexpr float kShotSpeed = 4.0f;		//弾のスピードの指定
}

void ShotPlayer::start(Vec2 pos)
{
	ShotBase::start(pos);
	m_vec.y -= kShotSpeed;					//弾が出る方向の指定
}

void ShotPlayer::update()
{
	m_pos += m_vec;

	if (m_pos.y < 0)
	{
		m_isExist = false;
	}
}