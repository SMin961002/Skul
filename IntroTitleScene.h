#pragma once
class IntroTitleScene : public Scene
{
public:
	CImage* img;
	CImage* imgtxt;
	CImage* imgTitle;
	float alpha;
	float alpha2;
	bool m_isTitleStart;
	bool isFade;
	float r = 0;
	IntroTitleScene() {}
	~IntroTitleScene() {}
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

