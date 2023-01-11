#pragma once
class SlotMachine :public Component
{
private:
	vector<Object*> m_vectorCollisionList;
	vector<Object*> m_vectorThunderList;
	vector<Object*> m_vectorThunderSmallList;

	CollisionComponent* m_coll;
	CollisionComponent* m_collThunderRange;
	CollisionComponent* m_collThunderSmallRange;
	vImage* m_imgSlotMachine;	//���Ըӽ� ���ư��� �ִϸ��̼� �̹���
	vImage* m_imgExplosion;		//���� �ִϸ��̼� �̹���
	CImage* m_imgResult;		//���Ըӽ� ��� �̹���

	int m_resultExplosion;	//���-���� ����
	int m_resultThunder;	//���-��� ����
	int m_resultLaiser;		//���-�Ķ� ����

	bool m_isLeft;
	bool m_slotMachineRunning;	//���Ըӽ� ���ư��� �̹��� ��»�Ȳ���� üĿ
	bool m_printResult;			//���Ըӽ� ������ Ʈ����
	bool m_action;				//����ȿ�� Ʈ����

	float m_delay;
	float m_alpha;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void Render() override;

	void CollisionUpdate();
	virtual void OnCollision(string collisionName, Object* other)override;
};

