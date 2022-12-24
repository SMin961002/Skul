#include "Stdafx.h"
#include "KeyManager.h"


KeyManager::KeyManager()
{
}

KeyManager::~KeyManager()
{
}


void KeyManager::Init(void)
{
	for (int i = 0; i < KEY_MAX; i++)
	{
		this->setKeyDown(i, false);
		this->setKeyUp(i, false);
	}
}

bool KeyManager::GetOnceKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x80000)
	{
		if (!this->getKeyDown()[key])
		{
			this->setKeyDown(key, true);
			return true;
		}
	}
	else this->setKeyDown(key, false);

	return false;
}

bool KeyManager::GetOnceKeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x80000)
	{
		this->setKeyUp(key, true);
	}
	else
	{
		if (this->getKeyUp()[key])
		{
			this->setKeyUp(key, false);
			return true;
		}
	}
	return false;
}

bool KeyManager::GetStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000) return true;
	return false;
}

bool KeyManager::GetToggleKey(int key)
{
	if (GetKeyState(key) & 0x0001) return true;
	return false;
}
