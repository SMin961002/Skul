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
		MessageBox(NULL, "�������̽���������", "SYSTEM ERROR", MB_OK);
		return false;
	}

	// ���� ����̽� �������� ����.
	if (FAILED(m_pSound->SetCooperativeLevel(hwnd, DISCL_EXCLUSIVE))) // Flag�� ����
	{
		MessageBox(NULL, "�������̽� �������� ����", "SYSTEM ERROR", MB_OK);
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