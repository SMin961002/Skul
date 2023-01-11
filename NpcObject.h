#pragma once
class NpcObject : public Component
{
public:
	struct sItem
	{
		int m_account;
		string key;
	};
	CollisionComponent* coll1;
	CollisionComponent* coll2;
	CollisionComponent* coll3;
	CollisionComponent* coll4;
	int kind;

	bool m_isState;
	vector<sItem*> m_itemList;
	float rot;
	NpcObject();
	~NpcObject();
	vImage* m_npcImage;
	vImage* m_shopImage;
	string m_name;
	// Component을(를) 통해 상속됨
	void Setting(string name);
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void UIRender() override;
	virtual void OnCollision(CollisionComponent* coll1, CollisionComponent* coll2, Object* other) override;
};

