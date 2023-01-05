#pragma once
#include"Enemy.h"
class AngelStatue : public Enemy
{
	enum ImageState
	{
		eIdle,
		eAttack,
		eEndAttack,
		eEnd
	};
	int m_state;
	vImage* m_vimage[eEnd];
	bool m_attack;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(string collisionName, Object* other) override;



};

