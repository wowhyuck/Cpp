#include "029_Player.h"
#include "029_Monster.h"


void Player::KillMonster()
{
	_target->KillMe();

	//_target->_hp = 0;
}

void Player::KillMonster2()
{
	_target->_hp = 0;
}