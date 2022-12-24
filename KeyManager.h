#pragma once
#include "singleton.h"
#define KEY_MAX 256

class KeyManager : public Singleton<KeyManager>
{
private:

	bitset<KEY_MAX> _keyUp;
	bitset<KEY_MAX> _keyDown;
public:
	KeyManager();
	~KeyManager();
public:
	void Init();
	bool GetOnceKeyDown(int key);
	bool GetOnceKeyUp(int key);
	bool GetStayKeyDown(int key);
	bool GetToggleKey(int key);

	bitset<KEY_MAX> getKeyUp(void) { return _keyUp; }
	bitset<KEY_MAX> getKeyDown(void) { return _keyDown; }

	void setKeyDown(int key, bool state) { _keyDown.set(key, state); }
	void setKeyUp(int key, bool state) { _keyUp.set(key, state); }
};

#define KEYMANAGER KeyManager::GetInstance()