#pragma once
class Thunder : public Component
{
private:
	vector<Object*> m_CollObjList;

	CollisionComponent* m_coll;
	Effect* m_thunder;

	bool m_isBigHit;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void Render() override;

	void CollisionUpdate();
	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)override;

	//BigHit여부를 전달받고 그에 따라 세팅 및 발동된다.
	void Setting(bool isBigHit)
	{
		m_isBigHit = isBigHit;
		if (isBigHit)
		{
			m_obj->y -= 172;
			m_thunder = EFFECTMANAGER->AddEffect<SlotMachineThunder>(m_obj->x, m_obj->y, false, 2);
		}
		else
		{
			m_thunder = EFFECTMANAGER->AddEffect<SlotMachineThunder>(m_obj->x, m_obj->y, false, 2);
		}
	};
};

class ThunderShoter : public Component
{
private:
	list<Object*> m_targetList;
	CollisionComponent* m_coll;
	float m_checkTargetRange;
	bool m_checkTarget;

	int m_shotCount;
	bool m_isBigHit;
	float m_delay;
	float m_dmg;

	bool m_shot;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override {};
	virtual void Render() override {};

	void CollisionUpdate();

	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other) override;
	void Setting(int resultCount)
	{
		switch (resultCount)
		{
		case 0:
			m_obj->ObjectDestroyed();
			break;

		case 2:
			m_shotCount = 3;
			m_dmg = 15;
			m_isBigHit = false;
			m_checkTarget = true;
			break;

		case 3:
			m_shotCount = 15;
			m_dmg = 20;
			m_isBigHit = true;
			m_checkTarget = false;
			m_coll->SetIsActive(false);
			break;

		case 1:
		default:
			m_shotCount = 1;
			m_dmg = 15;
			m_isBigHit = false;
			m_checkTarget = true;
			break;
		}
	}
	void ShotStart() { m_shot = true; m_checkTarget = false; m_coll->SetIsActive(false); };
};