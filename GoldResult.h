#pragma once
class GoldResult : public Component
{
public:
	vImage* img;
	GoldResult() {}
	~GoldResult() {}
	// Component을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

