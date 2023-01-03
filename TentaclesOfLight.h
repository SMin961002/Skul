#pragma once
#include"Enemy.h"
class TentaclesOfLight :public Enemy
{
private:
	enum ImageState
	{
		eIdle,
		eAttack,
		eRecovery,
		eMemerge,
		eEnd
	};

	vImage* m_vimage[eEnd];
	int m_state;
	bool m_attack;
	bool m_memergeend;
	bool m_isleft;
	bool m_recovery;

	CollisionComponent* m_collision;
	CollisionComponent* m_hitpointcollision;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(string collisionName, Object* other) override;

};

