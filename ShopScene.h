#pragma once
class ShopScene : public Scene
{
private:
	vector<vector<int>> m_tiles;
	vector<StructureData*> m_struectures;
	vector<StructureData*> m_objects;
public:
	CImage* m_backGround;
	CImage* m_cloude;
	CImage* m_structure;
	ShopScene() {}
	~ShopScene() {}
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

