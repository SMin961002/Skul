#pragma once
class Card : public Component
{
	//���� �븻 / ��Ŀ ī�� �ڽ�Ŭ������ �ϳ� ���� �� Init �������ϱ� - joker Explosion
	//���н� �Ϲ�ī�� 24�� �߻�
	//�븻������ ����ī��, spark effect, 15��
	//�뼺���� ����ī��(bighit small), ������ī�� big explosion, �� 30
	//���ʹ� Ÿ������ �ٲٱ�
protected:
	typedef list<Object*> listObj;

	const float m_speed = 500;
	CollisionComponent* m_coll;
 
	listObj m_CollObjList;
	CImage* m_img;
	float m_startX;
	bool m_isLeft;
	bool m_isJoker;
	bool m_isJokerHit;
	Effect* m_jokerExplosion;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(string collisionName, Object* other)override;

	Card() {}
	~Card() {}
};

class BlackJackCard : public Card
{
private:
	int m_success;
	float m_dmg;
	bool m_shoot;

	float m_dx;
	float m_dy;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	//����0, ���� -1, �뼺�� 1
	void Setting(int success);
	void SetShoot()
	{
		m_shoot = true;
		m_coll->SetIsActive(true);
		if (m_success >= 0)
			EFFECTMANAGER->AddEffect<BlackJackSpark>(m_obj->x, m_obj->y, m_isLeft, 2);
	}
	virtual void OnCollision(string collisionName, Object* other)override;
};