#pragma once
class SlotMachine :public Component
{
private:
	vector<Object*> m_vectorCollisionList;
	vector<Object*> m_vectorThunderList;
	vector<Object*> m_vectorThunderSmallList;

	CollisionComponent* m_coll;
	CollisionComponent* m_collThunderRange;
	CollisionComponent* m_collThunderSmallRange;
	vImage* m_imgSlotMachine;	//슬롯머신 돌아가는 애니메이션 이미지
	vImage* m_imgExplosion;		//폭발 애니메이션 이미지
	CImage* m_imgResult;		//슬롯머신 결과 이미지

	int m_resultExplosion;	//결과-빨강 갯수
	int m_resultThunder;	//결과-노랑 갯수
	int m_resultLaiser;		//결과-파랑 갯수

	bool m_isLeft;
	bool m_slotMachineRunning;	//슬롯머신 돌아가는 이미지 출력상황인지 체커
	bool m_printResult;			//슬롯머신 결과출력 트리거
	bool m_action;				//공격효과 트리거

	float m_delay;
	float m_alpha;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void Render() override;

	void CollisionUpdate();
	virtual void OnCollision(string collisionName, Object* other)override;
};

