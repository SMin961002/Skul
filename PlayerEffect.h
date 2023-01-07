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

class JokerExplosion : public Effect
{
public:
	void Init() override;
};