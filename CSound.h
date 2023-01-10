#pragma once
#include "CSoundMgr.h"

class CSound
{
private:
	LPDIRECTSOUNDBUFFER		m_pSoundBuffer;
	DSBUFFERDESC			m_tBuffInfo;
	int						m_iVolume;
public:
	int Load(const std::string _strPath);
	void Play(bool _bLoop = false);
	void PlayToBGM(bool _bLoop = false);
	void Stop(bool _bReset = false);
	void SetVolume(float _fVolume);
	void SetPosition(float _fPosition);
private:
	bool LoadWaveSound(const std::string _strPath);
	int GetDecibel(float _fVolume);
public:
	CSound();
	virtual ~CSound();
};

