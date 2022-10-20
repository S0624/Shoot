#pragma once
#include"Vec2.h"
#include"Enemy.h"

class ShotBase
{
public:
	ShotBase();
	virtual ~ShotBase();

	virtual void start(Vec2 pos);	//�V���b�g�J�n

	virtual void update();			// �X�V
	virtual void draw();			// �\��

	Vec2 getPos() const { return m_pos; }		//���̎擾
	Vec2 getBottomRight() const { return m_pos + m_size; }		//�E����W�̎擾

protected:
	Vec2	m_pos;					// �\���ʒu
	Vec2	m_vec;					// �ړ�
	Vec2	m_size;					// �T�C�Y
	bool m_isExist;					//���݂��邩
};