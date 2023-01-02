#pragma once
class DoorObject : public Component
{
private:
	enum DoorState
	{
		eNormal,
		eSkul,
	};
	CollisionComponent* m_coll;
	CImage* img;
	vImage* vimg;
	bool m_isChange = false;
	bool m_isClear = false;
	int m_kind;
public:
	DoorObject();
	~DoorObject();
	// Component을(를) 통해 상속됨
	void Setting(int state);
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void UIRender() override;
	virtual void OnCollision(string collisionName, Object* other) override;
};

