#pragma once
#include "Effect.h"

class Secrifice : public Effect
{
public:
	void Init() override;


	Secrifice() {};
	~Secrifice() {};
};

class SkulAttack : public Effect
{
public:
	void Init() override;


	SkulAttack() {};
	~SkulAttack() {};
};

class DeadEffect : public Effect
{
public:
	void Init() override;

	DeadEffect() {}
	~DeadEffect() {}

};

class Appear : public Effect
{
public:
	void Init() override;


	Appear() {};
	~Appear() {};
};