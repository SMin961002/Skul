#pragma once
#include"Enemy.h"
class LampFanatic : public Enemy 
{
	enum IamgeState
	{
		eIdle,
		eMass,
		eMassLoop,
		eMassReady,
		eMassReadyLoop,
		eRun,
		eSummonReady,
		eSummons,
		eEnd
	};

	vImage* m_vimage[eEnd];
	bool m_attack;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(string collisionName, Object* other) override;

};

