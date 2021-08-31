#include <iostream>
using namespace std;

// 오늘의 주제 : 참조

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 8;
	info.defence = 5;
}

// 값을 수정하지 않는다면, 양쪽 다 일단 문제 없음

// 1) 값 전달 방식
void PrintInfoByCopy(StatInfo info)
{
	cout << "----------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "----------------" << endl;
}

// 2) 주소 전달 방식
void PrintInfoByPtr(StatInfo* info)
{
	cout << "----------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "----------------" << endl;
}

// 3) 참조 전달 방식
void PrintInfoByRef(StatInfo& info)
{
	cout << "----------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "----------------" << endl;
}

// StatInfo 구조체가 1000바이트짜리 대형 구조체라면?
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사
// - (주소 전달) StatInfo*는 8바이트
// - (참조 전달) StatInfo&는 8바이트

// 참조 전달은 값 전달처럼 편리하게 사용
// 주소 전달처럼 주소값을 이용해 진짜를 건드림
// 일석이조의 방식!

int main()
{
	int number = 1;
	// 로우레벨(어셈블리) 관점에서 실제 작동 방식은 int*와 똑같음
	int& reference = number;
	reference = 3;
	// C++ 관점에서는 number라는 바구니에 또 다른 이름(reference)을 부여

	StatInfo info;
	CreateMonster(&info);

	PrintInfoByCopy(info);
	PrintInfoByPtr(&info);
	PrintInfoByRef(info);

	return 0;
}