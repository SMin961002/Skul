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
	template <class T>
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
};

