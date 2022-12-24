#pragma once
class MapToolScene : public Scene
{
private:
	vector<vector<int>> m_tiles;
	vector<CImage*> m_tileImages;
	int m_width;
	int m_kind = 0;
	const int m_maxIndex = 12;
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

