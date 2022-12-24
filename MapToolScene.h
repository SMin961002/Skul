#pragma once
class MapToolScene : public Scene
{
private:
	vector<vector<int>> m_tiles;
	vector<CImage*> m_tileImages;
	map<string,CImage*> m_structureImages;
	vector<StructureData*> m_sturctDatas;
	string m_streuctureKey;
	int m_width;
	int m_kind = 0;
	const int m_maxIndex = 12;
	enum eState
	{
		eTileBatch,
		eStructureBatch,
		eCollisionBatch,
	};
	int m_state;
	int m_page;

public:
	MapToolScene();
	~MapToolScene();

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

