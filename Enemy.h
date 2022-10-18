#pragma once
#include"Vec2.h"

class SceneMain;

class Enemy
{
public:
	Enemy();
	virtual ~Enemy() {}

	void init();				//������

	void setMain(SceneMain* pMain) { m_pMain = pMain; }			//�N���X�|�C���^��ݒ�

	void update();				//����
	void draw();				//�`��

	void Dead() { m_isDead = true; }

	Vec2 getPos() const { return m_pos; }		//���̎擾
	Vec2 getBottomRight() const { return m_pos + m_size; }		//�E����W�̎擾

	bool isDead()const { return m_isDead; }
private:
	SceneMain* m_pMain;			//SceneMain�̃|�C���^

	Vec2 m_pos;
	Vec2 m_vec;
	Vec2 m_size;

	//int m_shotInterval;			//�V���b�g�̔��ˊԊu

	bool m_isDead;
};