#pragma once
class ShopScene : public Scene
{
public:

	ShopScene() {}
	~ShopScene() {}
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

