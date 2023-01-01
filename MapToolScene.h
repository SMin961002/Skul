#pragma once
class MapToolScene : public Scene
{
private:
	map<string,CImage*> m_structureImages;
	map<string, CImage*> m_objectImages;

	vector<CImage*> m_tileImages;
	vector<vector<int>> m_tiles;
	vector<StructureData*> m_sturctDatas; // 구조물 
	vector<StructureData*> m_objectDatas; // 적이나 엔피시 등

	string m_streuctureKey;
	int m_width;
	int m_kind = 0;
	const int m_maxIndex = 12;
	enum eState
	{
		eTileBatch,
		eStructureBatch,
		eObjectBatch,
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

