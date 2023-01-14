#pragma once
class ResultValue : public Component
{
private:
	bool m_isCheck;
protected:
	vImage* m_idleImg;
	vImage* spanwImage;
	vImage* m_activeImg;
	CollisionComponent* com;
public:
	ResultValue() {}
	~ResultValue() {}
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other) override;
	bool isTr;
	virtual void Setting() PURE;
	virtual void Reword() PURE;
};

