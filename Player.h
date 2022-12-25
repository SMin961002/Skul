#pragma once
#include "Component.h"

#define MOVE_SPEED				3
#define JUMP_SPEED				3
#define DASH_MULTIPLE			2
#define DASH_COLLTIME			
#define COMMAND_ReENTRY_TIME	
#define HISTORY_MAX				10

enum SkulTag
{
	eBasic,
	ePredator,
	eDestroyer,
	eGambler
};
class Player : public Component
{
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

protected:
	RECT m_hitBox;
	//�̹����� �ൿ

//���ݽ�ų 2����
//�Ϲݰ���
//����
//��������
//���
//�̵�

public:
	vImage* img;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	virtual void Move();
	virtual void Action();
	virtual void Draw();
};