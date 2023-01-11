#pragma once
class Roulette: public Component
{
private:
	typedef list<Object*> listObj;

	enum Result
	{
		eBlack, eRed
	};
	int m_resultColor;
	int m_resultSuccess;	//-1실패 0성공 1대성공

	listObj m_CollObjList;
	vImage* m_roulette;
	vImage* m_explosion;
	CImage* m_imageResult;
	CollisionComponent* m_coll;

	bool m_printRouletteResult;
	bool m_boombRoulette;
	bool m_isInBreakEffect;
	bool m_isBlackBigHitSoundOn;
	float m_delay;
	short m_rouletteLoopCounter;

	float m_alpha;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	void CollisionUpdate();
	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other)override;

	void ResultAndImageSetting();
	int GetSuccess() { return m_resultSuccess; }
};

class BlackHole : public Component
{
private:
	vector<Object*> m_CollObjList;

};