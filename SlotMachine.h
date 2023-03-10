#pragma once
class ThunderShoter;
class SlotMachine :public Component
{
private:
	typedef list<Object*> listObj;

	listObj m_CollObjList;

	CollisionComponent* m_coll;
	vImage* m_imgSlotMachine;	//슬롯머신 돌아가는 애니메이션 이미지
	short m_loopChecker;
	vImage* m_imgExplosion;		//폭발 애니메이션 이미지
	CImage* m_imgResult;		//슬롯머신 결과 이미지
	ThunderShoter* m_thunder;
	
	int m_resultExplosion;	//결과-빨강 갯수
	int m_resultThunder;	//결과-노랑 갯수
	int m_resultLaiser;		//결과-파랑 갯수

	bool m_isLeft;
	bool m_slotMachineRunning;	//슬롯머신 돌아가는 이미지 출력상황인지 체커
	bool m_printResult;			//슬롯머신 결과출력 트리거
	bool m_actionThunder;				//공격효과 트리거
	bool m_actionExplosion;				//공격효과 트리거

	float m_delay;
	float m_alpha;
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void Render() override;

	void CollisionUpdate();
	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)override;
};

