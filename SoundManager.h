#pragma once
#include "singleton.h"
class SoundManager : public Singleton<SoundManager>
{
public:

	SoundManager() {}
	~SoundManager() {}

	void AddSound(std::string key, std::string path);
};

