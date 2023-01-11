#pragma once
class Card : public Component
{
	//블랙잭 노말 / 조커 카드 자식클래스로 하나 만든 뒤 Init 재정의하기 - joker Explosion
	//실패시 일반카드 24개 발사
	//노말성공시 관통카드, spark effect, 15뎀
	//대성공시 펑펑카드(bighit small), 마지막카드 big explosion, 뎀 30
	//에너미 타격판정 바꾸기
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
	//성공0, 실패 -1, 대성공 1
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