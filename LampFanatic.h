#pragma once
#include"Enemy.h"
class LampFanatic : public Enemy 
{
	enum ImageState
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
	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other) override;

};

