#pragma once

#include <Windows.h>
#include <SDKDDKVer.h>

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <mmsystem.h>
#include <functional>
#include <queue>
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <map>
#include <unordered_map>

#include <string>

#include <bitset>

#pragma region D2d1FactoryHeader
#pragma comment (lib, "msimg32.lib") 

#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>

#pragma comment(lib , "Dwrite.lib")
#pragma comment( lib, "dxerr.lib" )
#pragma comment( lib, "dxguid.lib" )
#pragma comment( lib, "d2d1.lib" )

#include <wincodecsdk.h>
#pragma comment(lib,"windowscodecs.lib")
#pragma endregion


using namespace std;

enum ObjectTag
{
	eObject,
	eEnemy,
	ePlayer,
	eEndTag
};

struct StructureData
{
	string key = "";
	float x = 0;
	float y = 0;
	bool isBack = false;
	int page = 0;
};

#define WIN_NAME "금강상태"
#define WINSTYLE WS_CAPTION | WS_SYSMENU
#define WINSTART_X 0
#define WINSTART_Y 0
#define WINSIZE_X 1100
#define WINSIZE_Y 560


static float g_TimeScale = 1;
static const float g_deltaTime;

#define TIME_SCALE g_TimeScale


#define SAFE_DELETE(p)       {if(p){delete(p); (p) = nullptr;}}   //안전하게 초기화
#define SAFE_DELETE_ARRAY(p) {if(p){delete[] (p); (p)=nullptr;}}  //복수 객체일 경우
#define SAFE_RELEASE(p)      {if(p) {(p)->release();(p)=nullptr;}

extern HWND _hWnd;
extern POINT _ptMouse;
#include "TimerManager.h"

struct Vector2
{
	float x;
	float y;
};
#define DELTA_TIME TIME_SCALE *  TimerManager::GetInstance()->GetElapsedTime()
#include "ObjectManager.h"
#include "KeyManager.h"
#include "ImageManager.h"
#include "SceneManager.h"
#include "IOFillManager.h"
#include "Utility.h"
//inline static float GetDeltaTime()
//{
//	return;
//}


extern HINSTANCE hInst;

