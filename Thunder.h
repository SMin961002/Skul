#pragma once
class Thunder : public Component
{
private:
	typedef list<Object*> listObj;

	listObj m_CollObjList;

	CollisionComponent* m_coll;
	//vImage* m_imgThunder;
	Effect* m_thunder;
	float m_dmg;
	float m_delay;

	bool m_isBigHit;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void Render() override;

	void CollisionUpdate();
	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)override;

	//BigHit여부를 전달받고 그에 따라 세팅 및 발동된다.
	void Setting(bool isBigHit, float dmg)
	{
		m_isBigHit = isBigHit;
		m_dmg = dmg;
		if (isBigHit)
		{
			m_obj->y -= 200;
			m_thunder = EFFECTMANAGER->AddEffect<SlotMachineThunderBigHit>(m_obj->x, m_obj->y, false, 2);
			string sound = "SlotMachineThunder3Impact";
			char a = MY_UTILITY::getFromIntTo(65, 67);
			sound.append(1, a);
			SOUNDMANAGER->FindSound(sound)->Play(false);
		}
		else
		{
			m_thunder = EFFECTMANAGER->AddEffect<SlotMachineThunder>(m_obj->x, m_obj->y, false, 2);
			SOUNDMANAGER->FindSound("SlotMachineThunder")->Play(false);
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
			m_dmg = 10;
			m_isBigHit = false;
			m_checkTarget = true;
			break;

		case 3:
			m_shotCount = 20;
			m_dmg = 12;
			m_isBigHit = true;
			m_checkTarget = false;
			m_coll->SetIsActive(false);
			break;

		case 1:
		default:
			m_shotCount = 1;
			m_dmg = 10;
			m_isBigHit = false;
			m_checkTarget = true;
			break;
		}
	}
	void ShotStart() { 
		m_shot = true; 
		m_checkTarget = false; 
		m_coll->SetIsActive(false); 
		if (m_isBigHit)
		{
			SOUNDMANAGER->FindSound("SlotMachineThunder3")->Play(false);
			EFFECTMANAGER->AddEffect<SlotMachineThunder>(m_obj->x, m_obj->y, false, 2);
		}
	};
};