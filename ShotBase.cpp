#include"DxLib.h"
#include"ShotBase.h"

ShotBase::ShotBase()
{
	m_pos.x = 0.0f;
	m_pos.y = 0.0f;
	m_vec.y = 0.0f;

	m_size.x = 0.0f;
	m_size.y = 40.0f;
	m_isExist = false;
}

ShotBase::~ShotBase()
{

}

void ShotBase::start(Vec2 pos)
{
	m_isExist = true;
	m_pos = pos;
}

void ShotBase::update()
{
	if (!m_isExist)return;
}

void ShotBase::draw()
{
	if (!m_isExist)return;
	DrawLine(m_pos.x, m_pos.y, m_pos.x, m_pos.y + m_size.y, GetColor(255, 255, 255));    // ’e‚ð•`‰æ
}