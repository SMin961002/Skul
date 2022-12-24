#pragma once

class Timer
{

private:
	float		_timeScale;   // 경과시간 조절
	float		_timeElapsed; // 마지막 시간과 현재시간의 경과값
	bool		_isHardware;   // 고성능 타이머 지원 여부

	__int64		_curTime; //  현재시간 __int 32 or 64(몆비트 사용하는지) 실행파일로 뽑아냈을때 64 ,32 갈림 __int64 32비트를 64로 강제로 바꿔준다 __ <- 표준어는 아니라는것
	__int64		_lastTime; // 이전시간
	__int64		_periodFrequency; // 시간 주기

	/*

	__int64 vs long

	- int vs lonng
	32비트에서 롱은 4비트 -> 64비트에서롱은 8비트
	*/

	unsigned long _frameRate;  //(초당프레임수)
	unsigned long   _FPSFrameCount; //fps 카운트
	float			_FPSTimeElapsed; //FPS 시간 경과량
	float			_worldTime;		 // 게임이 시작된 후 경과된 전체시간


public:
	HRESULT init(void);
	void tick(float lockFPS = 0.0f);


	//현재 FPS
	unsigned long gerFrameRate(char* str = nullptr) const; //?
	//마지막 시간과 현재 시간의 경과량
	inline float getElapsedTime(void) const { return _timeElapsed; } //?
	// 전체 경과 시간
	inline float getWorldTime(void) const { return _worldTime; } //?
	// 멤버함수의 끝에 컨스트가 뒤로 들어갔을때 -> 멤버함수의 상수화를 의미
	// ㄴ 이 함수내에서 멤버 변수의 값 변경을 막는다.
	// ㄴ 멤버변수가 변경될 수 있는 기회를 주지 않으며 변수 역시 변경 불가
	// ㄴ 포인터 x
	// 외부에서 값변경을 못하게 하기위해 막아줌

	// Timer -> Timer manger로 드갈것

	// 참고 -> 게임업계에서는 UPDATE잘 안씀 (프레임 드랍으로 인해 조건문들 통과하지 못하는경우도있음)
	// 위에 타이머로 뽑을경우 일정하게 뽑아낼수 있다



public:
	Timer() {};
	~Timer() {};
};

