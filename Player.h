#pragma once
#include "Component.h"

#define MOVE_SPEED	3
#define JUMP_SPEED	3
#define DASH_MULTIPLE	2
#define DASH_COLLTIME	
#define COMMAND_ReENTRY_TIME

enum SkulTag
{
	eBasic,
	ePredator,
	eDestroyer,
	eGambler
};
class Player : public Component
{
	//���ݽ�ų 2����
	//�Ϲݰ���
	//����
	//��������
	//���
	//�̵�
	/*
	����2ȸ, ���2ȸ ���Ⱑ��
	������ ��� �� ���ƿ��� �� ��� ��Ʈ ����,
	1����->2�ܴ��->2����->2�ܴ��->����������� 2�ܴ�� ����
	(�߶����� ������ �߰���� �� ����)
	ù ��� ������ �������� 2ȸ�� ��� ����
	
	1ȸ�� ��� ���� �����ð� �̳��� ���Ű ������ 2ȸ�� ��� ����
	(�ȱ׷��� �� ���ư�. �� ���������� ��� �Ұ�)
	��� ��Ž�м���
	���������� ��ȸ���� �Ǵ��� �м� �ʿ�
	*/

private:
	RECT m_hitBox;

public:
	virtual enum ActionTag
	{
		eAutoAttack_1,
		eAutoAttack_2,
		eJump,
		eDash,
		eSkill_1,
		eSkill_2,
		eIdle
	};

	vImage* img;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void move();
	virtual void draw();
};