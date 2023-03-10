#pragma once
#include <dsound.h>
#include <dinput.h>

#pragma comment(lib, "dsound.lib")

class CSound;
class CSoundMgr : public Singleton<CSoundMgr>
{
private:
	LPDIRECTSOUND8	m_pSound;	// 사운드카드 대표 객체
	CSound* m_pBGM;		// 현재 지정된 BGM Sound
	map<string, CSound*> m_sounds;
public:
	CSoundMgr();
	~CSoundMgr();
	int init(HWND hwnd);
	LPDIRECTSOUND8 GetSoundDevice() { return m_pSound; }
	void RegisterToBGM(CSound* _pSound);

	CSound* AddSound(string key, string path);
	CSound* FindSound(string key);
};

#define SOUNDMANAGER CSoundMgr::GetInstance()