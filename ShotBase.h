#pragma once
#include"Vec2.h"

class ShotBase
{
public:
	ShotBase();
	virtual ~ShotBase();

	virtual void start(Vec2 pos);	//�V���b�g�J�n

	virtual void update();			// �X�V
	virtual void draw();			// �\��

	virtual float getRadius()const;	//�����蔻��̔��a�̎擾
	virtual Vec2 getCenter()const;	//�����蔻��̒��S�ʒu�擾

	bool isExsist()const { return m_isExist; }	//���݂��邩

protected:
	Vec2	m_pos;					// �\���ʒu
	Vec2	m_vec;					// �ړ�
	Vec2	m_size;					// �T�C�Y
	bool m_isExist;					//���݂��邩
};