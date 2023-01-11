#include "stdafx.h"
#include "CSoundMgr.h"
#include "CSound.h" 

CSoundMgr::CSoundMgr()
	: m_pSound(nullptr)
	, m_pBGM(nullptr)
{
}

CSoundMgr::~CSoundMgr()
{
}

int CSoundMgr::init(HWND hwnd)
{
	if (FAILED(DirectSoundCreate8(NULL, &m_pSound, NULL)))
	{
		MessageBox(NULL, "사운드디바이스생성실패", "SYSTEM ERROR", MB_OK);
		return false;
	}

	// 사운드 디바이스 협조레벨 설정.
	if (FAILED(m_pSound->SetCooperativeLevel(hwnd, DISCL_EXCLUSIVE))) // Flag값 정리
	{
		MessageBox(NULL, "사운드디바이스 협조레벨 설정", "SYSTEM ERROR", MB_OK);
		return false;
	}

	return true;
}

void CSoundMgr::RegisterToBGM(CSound* _pSound)
{
	if (m_pBGM != nullptr)
		m_pBGM->Stop(true);

	m_pBGM = _pSound;
}

CSound* CSoundMgr::AddSound(string key, string path)
{
	CSound* sound = new CSound;
	sound->Load(path);
	m_sounds.insert(make_pair(key, sound));
	return sound;
}

CSound* CSoundMgr::FindSound(string key)
{
	auto find = m_sounds.find(key);
	return find->second;
}
