#pragma once
#include "singleton.h"
#include <fstream>

class IOFillManager : public Singleton<IOFillManager>
{
private:
	string m_nowStageFileName;
public:
	IOFillManager();
	~IOFillManager();
public:
	HRESULT TileFileRead(vector<vector<int>>* tiles);
	void TileFileWrite(string section, string key, vector<vector<int>> vec);

	HRESULT MapFileRead(string section, string key, vector<string>* mapList);
	void MapFileWrite(string section, string key, vector<string> mapList, LPCSTR mapName);

	void SetNowStageFile(string st) { m_nowStageFileName = st; }

	string GetFileData(string section, string key);
	void WriteFileData(string section, string key, string inputStr);
	
	string GetFileName(void) { return m_nowStageFileName; }
};

#define FILEMANAGER IOFillManager::GetInstance()