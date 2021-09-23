﻿#include <iostream>
using namespace std;

// 오늘의 주제 : 얕은 복사 vs 깊은 복사


class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}

	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}

	~Pet()
	{
		cout << "~Pet()" << endl;
	}
};

class Knight
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet);		// 깊은 복사
	}

	Knight& operator=(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet);		// 깊은 복사
		return *this;
	}

	~Knight()
	{
		delete _pet;
	}

public:
	int _hp = 100;
	Pet* _pet;
};

int main()
{
	Knight knight;		// 기본 생성자
	knight._hp = 200;

	Knight knight2 = knight;	// 복사 생성자
	//Knight knight3(knight);

	Knight knight3;		// 기본 생성자
	knight3 = knight;	// 복사 대입 연산자

	// [복사 생성자] + [복사 대입 연산자]
	// 둘 다 안 만들어주면 컴파일러가 '암시적으로' 만들어준다

	// [얕은 복사 Shallow Copy]
	// 멤버 데이터를 비트열 단위로 '똑같이' 복사 (메모리 영역 값을 그대로 복사)
	// 포인터는 주소값 바구니 -> 주소값을 똑같이 복사 -> 동일 객체를 가리키는 상태가 됨
	// Stack : Knight1[ hp 0x1000 ] -> Heap 0x1000 Pet[ ]
	// Stack : Knight2[ hp 0x1000 ]
	// Stack : Knight3[ hp 0x1000 ]

	// [깊은 복사 Deep Copy]
	// 멤버 데이터가 참조(주소) 값이라면. 데이터를 새로 만들어준다 (원본 객체가 참조하는 대상까지 새로 만들어서 복사)
	// 포인터는 주소값 바구니 -> 새로운 객체를 생성 -> 서로 다른 객체를 가리키는 상태가 됨
	// Stack : Knight1[ hp 0x1000 ] -> Heap 0x1000 Pet[ ]
	// Stack : Knight2[ hp 0x2000 ] -> Heap 0x2000 Pet[ ]
	// Stack : Knight3[ hp 0x3000 ] -> Heap 0x3000 Pet[ ]

	return 0;
}