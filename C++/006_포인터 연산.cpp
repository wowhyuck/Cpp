#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 연산

// 1) 주소 연산자 (&)
// 2) 산술 연산자
// 3) 간접 연산자 (*)
// 4) 간접 멤버 연산자 (->)

struct Player
{
	int hp;		// +0
	int damage;	// +4
};


int main()
{
	int number = 1;

	// 1) 주소 연산자 (&)
	// - 해당 변수의 주소를 알려주세요~
	// - 더 정확히 말하면 해당 변수 타입(TYPE)에 따라서 TYPE* 반환
	int* pointer = &number;


	// 2) 산술 연산자 (+ -)
	number += 1;	// 1 증가

	// int*
	// - * : 포인터 타입 (4 or 8 바이트)
	// - int : 주소를 따라가면 int가 있다고 가정

	// [!] 포인터에서 +나 -등 산술연산으로 1을 더하거나 빼면
	// 한번에 TYPE의 크기만큼 이동
	// 다음/이전 바구니로 이동하고 싶다 <- [바구니 단위]의 이동

	pointer += 1;	// 4 증가


	// 3) 간접 연산자 (*)
	// - 포탈을 타고 해당 주소로 이동
	number = 3;
	*pointer = 3;

	Player player;
	player.hp = 100;
	player.damage = 10;

	Player* playerPtr = &player;
	(*playerPtr).hp = 200;
	(*playerPtr).damage = 20;


	// 4) 간접 멤버 연산자 (->)
	// * 간접 연산자 (포탈을 타고 해당 주소로 이동)
	// . 구조체의 특정 멤버를 다룰 때 사용 (어셈블리 언어로 까보면 . 사실상 그냥 덧셈)
	// ->는 *와 . 한 방에!
	playerPtr->hp = 300;
	playerPtr->damage = 30;

	return 0;
}