#pragma once

//#include "029_Monster.h"
class Monster;

// class는 설계도
class Player
{
public:
	void KillMonster();
	void KillMonster2();

public:
	int _playerId;
	int _hp;
	int _attack;

	//Monster _target;
	Monster* _target;

	Player* _targetPlayer;
};