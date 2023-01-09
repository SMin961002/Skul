#pragma once
class Roulette: public Component
{
private:
	enum Result
	{
		eBlack, eRed
	};
	int m_result;
	vector<Object*> m_vectorCollisionList;
	vImage* m_roulette;
	CImage* m_imageResult;
	CollisionComponent* m_coll;
	
	int m_rotateCount;
	bool m_printResult;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(string collisionName, Object* other)override;
};

class BlackHole : public Component
{
private:
	vector<Object*> m_vectorCollisionList;

};