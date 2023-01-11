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
	virtual void OnCollision(string collisionName, Object* other)override;

	//BigHit여부를 전달받고 그에 따라 세팅 및 발동된다.
	void Setting(bool isBigHit)
	{
		m_isBigHit = isBigHit;
		if (isBigHit)
		{
			m_obj->y -= 200;
			m_thunder = EFFECTMANAGER->AddEffect<SlotMachineThunder>(m_obj->x, m_obj->y, false, 2);
		}
		else
		{		
			m_thunder = EFFECTMANAGER->AddEffect<SlotMachineThunder>(m_obj->x, m_obj->y, false, 2);
		}
	};
};

