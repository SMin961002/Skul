#pragma once
class ResultValue : public Component
{
private:
	bool m_isCheck;
protected:
	vImage* m_idleImg;
	vImage* m_activeImg;
public:
	ResultValue() {}
	~ResultValue() {}
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other) override;

	virtual void Setting() PURE;
	virtual void Reword() PURE;
};

