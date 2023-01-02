#pragma once
class EnemyTestScene : public Scene
{
private:
	bool isStart = false;
	CImage* m_backGround;
	CImage* m_cloude;
	float m_speed;
	CImage* m_castle;
	vector<StructureData*> m_sturctDatas;
	vector<StructureData*> m_objectDatas;
public:
	EnemyTestScene();
	~EnemyTestScene();
	// Scene을(를) 통해 상속됨
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void UIRender() override;
};

