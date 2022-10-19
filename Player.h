#pragma once
#include"Vec2.h"
#include"Enemy.h"

class SceneMain;

class Player
{
public:
	Player();
	virtual ~Player(){}

	void init();				//������

	void setMain(SceneMain* pMain) { m_pMain = pMain; }			//�N���X�|�C���^��ݒ�
	
	void update();				//����
	void draw();				//�`��
	void end();

	Vec2 getPos() const { return m_pos; }		//���̎擾

private:
	SceneMain* m_pMain;			//SceneMain�̃|�C���^

	Vec2 m_pos;
	Vec2 m_vec;
	Vec2 m_size;
	
	Enemy m_enemy;

	int m_shotInterval;			//�V���b�g�̔��ˊԊu
};