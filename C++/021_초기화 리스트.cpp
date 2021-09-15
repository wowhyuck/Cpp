﻿#include <iostream>
using namespace std;

// 오늘의 주제 : 초기화 리스트

// 초기화 하는 이유
// - 버그 예방에 중요
// - 포인터 등 주소값이 연루되어 있을 경우

// 초기화 방법
// - 생성자 내에서
// - 초기화 리스트
// - C++11 문법

// 초기화 리스트
// - 상속 관계에서 원하는 부모 생성자 호출할 때 필요하다.
// - 생성자 내에서 초기화 vs 초기화 리스트
// -- 일반 변수는 별 차이 없음
// -- 멤버 타입이 클래스인 경우 차이가 난다
// -- 정의함과 동시에 초기화가 필요한 경우(참조 타입, const 타입)

class Inventory
{
public:
	Inventory() { cout << "Inventory()" << endl; }
	Inventory(int size) { cout << "Inventory(int)" << endl; }

	~Inventory() { cout << "~Inventory()" << endl; }

public:
	int _size = 10;
};

class Player
{
public:
	Player() {}
	Player(int id) {}
};

// Is-A (Knight Is-A Player? 기사는 플레이어다) OK -> 상속관계
// Has-A (Knight Has-A Inventory? 기사는 인벤토리를 갖고 있다) NO -> 포함관계

class Knight : public Player
{
public:
	Knight() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100)
		/*
		선처리 영역

		_inventory = Inventory();

		*/
	{
		_hp = 100;
	}

public:
	int _hp = 200;		// 쓰레기값
	Inventory _inventory;

	int& _hpRef;
	const int _hpConst;
};

int main()
{

	return 0;
}