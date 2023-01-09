#pragma once
//#include "Component.h"
class Card : public Component
{
	//���� �븻 / ��Ŀ ī�� �ڽ�Ŭ������ �ϳ� ���� �� Init �������ϱ� - joker Explosion
	//���н� �Ϲ�ī�� 24�� �߻�
	//�븻������ ����ī��, spark effect, 15��
	//�뼺���� ����ī��(bighit small), ������ī�� big explosion, �� 30
	//�������ʹ� Ÿ������ �ٲٱ�
protected:
	const float m_speed = 500;
	CollisionComponent* m_coll;
	vector<Object*> m_vectorCollisionList;
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

	Card(){}
	~Card(){}
};

class BlackJackCard : public Card
{
private:
	float m_dmg;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	//����0, ���� -1, �뼺�� 1
	void Setting(int success);

	virtual void OnCollision(string collisionName, Object* other)override;
};