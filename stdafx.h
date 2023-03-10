#pragma once
#include <SDKDDKVer.h>
#pragma comment (lib, "msimg32.lib") //마이크로소프트(ms) 이미지(img) 32비트(32) 라이브러리


#include <wincodecsdk.h>
#pragma comment(lib,"windowscodecs.lib")
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

#include <windows.h>
#include <functional>
#include <locale>
#include <codecvt>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <math.h>
#include <tchar.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono> 
#include <random>
#include <time.h>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <unordered_map> 
#include <time.h>
#include <string>
#include <queue>
#include <bitset>

#pragma region D2d1FactoryHeader
#pragma comment (lib, "msimg32.lib") 

#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <dwrite_3.h>
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
	eNPC,
	eSummons,
	ePlayerProjectile,
	eEnemy,
	eItem,
	eBoss,
	ePlayer,
	eBossObject,
	eBossObject2,
	eEndTag
};

enum ItemTag
{
	eCaerleonSword,
	eEnd
};

struct StructureData
{
	string key = "";
	float x = 0;
	float y = 0;
	bool isBack = false;
	int page = 0;
};

enum class eSkulSpecies
{
	eBasic,
	ePredator,
	eDestroyer,
	eGambler,
	Empty
};

#define WIN_NAME "금강상태"
#define WINSTYLE WS_CAPTION | WS_SYSMENU
#define WINSTART_X 0
#define WINSTART_Y 0
#define WINSIZE_X 1100
#define WINSIZE_Y 560


extern float g_TimeScale;

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
#define DELTA_TIME g_TimeScale *  TimerManager::GetInstance()->GetElapsedTime()
#include "ObjectManager.h"
#include "KeyManager.h"
#include "ImageManager.h"
#include "SceneManager.h"
#include "IOFillManager.h"
#include "Utility.h"
#include "EffectManager.h"
#include "CSoundMgr.h"
#include "GameManager.h"
//inline static float GetDeltaTime()
//{
//	return;
//}


extern HINSTANCE hInst;

