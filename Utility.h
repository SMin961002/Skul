#pragma once
#include <sstream>
#include <istream>
namespace MY_UTILITY // utility
{
	// 2차원 벡터 변환 vec -> string
	inline void ConvertVecs2String(vector<vector<int>> vec, string* str)
	{
		std::stringstream ss;
		for (auto iter = vec.begin(); iter != vec.end(); iter++) {
			for (auto _iter = (*iter).begin(); _iter != (*iter).end(); _iter++)
			{
				if (_iter != (iter)->begin())
				{
					ss << ",";
				}
				ss << *_iter;
			}
			ss << " ";
		}
		*str = ss.str();
	}

	// 2차원 벡터 변환 string -> vec
	inline void ConvertString2Vecs(vector<vector<int>>* vec, string str)
	{
		istringstream iss(str);
		string buffer;
		vector<string> result;
		while (getline(iss, buffer, '/')) {
			result.push_back(buffer);
		}
		for (auto iter : result)
		{
			istringstream iss2(iter);
			string buffer2;
			vector<int> strVec;
			while (getline(iss2, buffer, ' ')) {
				strVec.push_back(stoi(buffer));
			}
			vec->push_back(strVec);
		}
	}

	// 1차원 벡터 변환 string -> vec
	inline void ConvertString2Vec(vector<int>* vec, string str)
	{
		istringstream iss(str);
		string buffer;
		vector<int> _vec;
		while (getline(iss, buffer, ',')) {
			_vec.push_back(stoi(buffer));
		}
		*vec = _vec;
	}

	// 1차원 벡터 변환 vec -> str
	template <class T> // 여기서 앞으로 템플릿화 사용하지 말아야 할듯
	inline void ConvertVec2String(vector<T> vec, string* str)
	{
		std::stringstream ss;
		for (auto iter = vec.begin(); iter != vec.end(); iter++) {

			if (iter != vec.begin())
			{
				ss << " ";
			}
			ss << *iter;
		}
		*str = ss.str();
	}

	inline void ConvertVec2StructureString(vector<StructureData*> vec, string* str)
	{
		std::stringstream ss;
		for (auto iter = vec.begin(); iter != vec.end(); iter++) {

			if (iter != vec.begin())
			{
				ss << " ";
			}
			ss << (*iter)->isBack;
			ss << ",";
			ss << (*iter)->key;
			ss << ",";
			ss << (*iter)->x;
			ss << ",";
			ss << (*iter)->y;
			ss << ",";
			ss << (*iter)->page;
		}
		*str = ss.str();
	}

	inline void ConvertStructureString2Vec(vector<StructureData*>* vec, string str)
	{
		istringstream is(str);

		string buffer;
		queue<string> _vec;
		while (getline(is, buffer, ' '))
		{
			string buffer2;
			istringstream iss(buffer);
			while (getline(iss, buffer2, ',')) {
				_vec.push(buffer2);
			}
			StructureData* sd = new StructureData;
			sd->isBack = stoi(_vec.front());
			_vec.pop();
			sd->key = _vec.front();
			_vec.pop();
			sd->x = stoi(_vec.front());
			_vec.pop();
			sd->y = stoi(_vec.front());
			_vec.pop();
			sd->page = stoi(_vec.front());
			_vec.pop();
			vec->push_back(sd);
		}
	}

	inline Vector2 GetLerpVec2(Vector2* vec, Vector2 vec1, Vector2 vec2, float t)
	{
		vec->x = vec1.x * (1 - t) + vec2.x * t;
		vec->y = vec1.y * (1 - t) + vec2.y * t;
		return *vec;
	}

	inline int getInt(int num)
	{
		return rand() % num;
	}

	inline int getFromIntTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum + 1) + fromNum;
	}

	inline float getFloat(void)
	{
		return (float)rand() / (float)RAND_MAX;
	}

	inline float getFloat(float num)
	{
		return (float)rand() / (float)RAND_MAX * num;
	}
	inline float getFromFloatTo(float fromNum, float toNum)
	{
		float rnd = (float)rand() / (float)RAND_MAX;
		return (rnd * (toNum - fromNum)) + fromNum;
	}
	inline float GetDistance(float startX, float startY, float endX, float endY)
	{
		float x = endX - startX;
		float y = endY - startY;
		return sqrt(x * x + y * y);
	}
};