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

	int m_rotateCount;
	bool m_printRouletteResult;
	bool m_boombRoulette;
	bool m_isInBreakEffect;
	float m_delay;

	float m_alpha;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	void CollisionUpdate();
	virtual void OnCollision(string collisionName, Object* other)override;

	void ResultAndImageSetting();
	int GetSuccess() { return m_resultSuccess; }
};

class BlackHole : public Component
{
private:
	vector<Object*> m_CollObjList;

};