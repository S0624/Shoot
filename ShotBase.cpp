#include"DxLib.h"
#include"ShotBase.h"

namespace
{
	constexpr int kPos_y = 20;
	constexpr int kRadius = 10;
}

ShotBase::ShotBase()
{
	m_pos.x = 0.0f;
	m_pos.y = 0.0f;
	m_vec.y = 0.0f;
	m_size = 0.0f;
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
	DrawLine(m_pos.x, m_pos.y, m_pos.x, m_pos.y + kPos_y, GetColor(255, 255, 255));    // 弾を描画
	//DrawCircle(getCenter().x, getCenter().y, getRadius(), GetColor(0, 255, 255), false);
	DrawBox(getPos().x -2, getPos().y -2, getPos().x +2, getPos().y + kPos_y +2, GetColor(255, 0, 255), false);			//当たり判定

	DrawFormatString(0, 500, GetColor(0, 255, 0), "弾座標:%f %f", getPos().x, getPos().y);					//デバッグのための表示
}



//float ShotBase::getRadius()const
//{
//	return kRadius;
//}
//Vec2 ShotBase::getCenter()const
//{
//	//int sizeX = 0;
//	//int sizeY = 0;
//	
//	//Vec2 result = m_pos;
//	//result.x += sizeX / 2;
//	//result.y += sizeY / 2;
//
//	return m_pos;
//}