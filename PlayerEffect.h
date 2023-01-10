#pragma once
#include "Effect.h"
class DoubleJumpSmoke : public Effect
{
public:
	void Init() override;
};

class DashSmoke : public Effect
{
public:
	void Init() override;
};

class PlayerHit : public Effect
{
public:
	void Init() override;
};

class TeleportationToHead : public Effect
{
public:
	void Init() override;
};

class GamblerAttack_1 : public Effect
{
private :
	bool m_effectOverap = false;
public:
	void Init() override;
};

class GamblerAttack_2 : public Effect
{
public:
	void Init() override;
};

class GamblerJumpAttack : public Effect
{
private:
	bool m_effectOverap = false;
public:
	void Init() override;
};

class JokerExplosion : public Effect
{
public:
	void Init() override;
};

class BlackJackJokerExplosion : public Effect
{
public:
	void Init() override;
};

class BlackJackSpark : public Effect
{
public:
	void Init() override;
	void Move() override;
};

class RouletteReady : public Effect
{
public:
	void Init() override;
};

class RouletteShot : public Effect
{
public:
	void Init() override;
};

class RouletteBigShot : public Effect
{
public:
	void Init() override;
};

class RouletteBrokenEffect : public Effect
{
public:
	void Init() override;
};
class RouletteBrokenEffectBigShot : public Effect
{
public:
	void Init() override;
};

class SlotMachineBigHit : public Effect
{
public:
	void Init() override;
	void Move() override;
};
class SlotMachineThunder :public Effect
{
public :
	void Init() override;
};