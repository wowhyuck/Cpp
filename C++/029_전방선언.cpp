#include <iostream>
#include "029_Player.h"

using namespace std;

// 오늘의 주제 : 전방선언


int main()
{
	Player p1;		// 지역변수 (Stack)

	Player* p2 = new Player();		// 동적할당 (Heap)

	p1._targetPlayer = p2;

	return 0;
}