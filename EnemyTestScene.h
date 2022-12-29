#pragma once
class EnemyTestScene : public Scene
{
private:
	CImage* m_backGround;
	CImage* m_cloude;
	float m_speed;
	CImage* m_castle;
	vector<vector<int>> m_tiles;
	vector<StructureData*> m_sturctDatas;
public:
	EnemyTestScene();
	~EnemyTestScene();
	// Scene��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

