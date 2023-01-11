#pragma once
class IllusionEffect : public Component
{
public:
	CImage* img;
	bool isLeft;
	bool alphaGo;
	float preAlphaTime;
	IllusionEffect() {}
	~IllusionEffect() {}
	// Component을(를) 통해 상속됨
	float alpha;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

	void Setting(CImage* _img, bool isLeft) { img = _img; this->isLeft = isLeft; }
};

