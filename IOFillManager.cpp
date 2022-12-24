#include "stdafx.h"
#include "IOFillManager.h"

IOFillManager::IOFillManager()
{
}

IOFillManager::~IOFillManager()
{
}

HRESULT IOFillManager::TileFileRead(vector<vector<int>>* tiles)
{
	string str;
	string path = "./MapFile/" + m_nowStageFileName + ".txt";
	ifstream inputFile(path);
	if (inputFile.fail())
	{
		return S_FALSE;
	}
	vector<int> lists;
	while (inputFile >> str)
	{
		cout << str << endl;
		MY_UTILITY::ConvertString2Vec(&lists, str);
		tiles->push_back(lists);
	}
	inputFile.close();

	return S_OK;
}

void IOFillManager::TileFileWrite(string section, string key, vector<vector<int>> vec)
{
	string vecValue;
	string path = "./MapFile/" + m_nowStageFileName + ".txt";


	MY_UTILITY::ConvertVecs2String(vec, &vecValue);

	ofstream outputFile(path);

	outputFile.clear();

	outputFile << vecValue;
	outputFile.close();
}

HRESULT IOFillManager::MapFileRead(string section, string key, vector<string>* mapList)
{
	string str;
	ifstream inputFile("./MapFile/mapList.txt");
	if (inputFile.fail())
	{
		return S_FALSE;
	}
	while (inputFile >> str)
	{
		cout << str << endl;
		mapList->push_back(str);
	}
	inputFile.close();
	return S_OK;
}

void IOFillManager::MapFileWrite(string section, string key, vector<string> mapList, LPCSTR mapName)
{
	string vecValue;
	MY_UTILITY::ConvertVec2String<string>(mapList, &vecValue);

	ofstream outputFile("./MapFile/mapList.txt");

	outputFile.clear();

	outputFile << vecValue;
	outputFile.close();
}
