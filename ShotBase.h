#pragma once
#include"Vec2.h"

class ShotBase
{
public:
	ShotBase();
	~ShotBase();

	//�V���b�g�J�n
	virtual void start(Vec2 pos);

	// �X�V
	virtual void update();
	// �\��
	virtual void draw();

	//���݂��邩
	bool isExsist()const { return m_isExist; }

protected:
	// �\���ʒu
	Vec2	m_pos;
	// �ړ�
	Vec2	m_vec;
	//���݂��邩
	bool m_isExist;
};