#include <iostream>

using namespace std;

// 오늘의 주제 : 함수 포인터

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

class Item
{
public:
	Item() : _itemId(0), _rarity(0), _ownerId(0)
	{

	}

public:
	int _itemId;		// 아이템을 구현하기 위한 ID
	int _rarity;		// 희귀도
	int _ownerId;		// 소지자 ID
};

typedef bool(ITEM_SELECTOR)(Item*, int);

Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector, int value)
{
	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		//TODO 조건
		if (selector(item, value))
			return item;
	}

	return nullptr;
}

bool isRareItem(Item* item, int value)
{
	return item->_rarity >= value;
}

bool isOwnerItem(Item* item, int ownerId)
{
	return item->_ownerId == ownerId;
}

class Knight
{
public:
	// 멤버 함수
	int GetHp(int a, int b)
	{
		cout << "GetHp()" << endl;
		return _hp;
	}

public:
	int _hp = 100;
};


int main()
{
	int a = 0;
	typedef int DATA;

	// 1) 포인터		*
	// 2) 변수 이름		pointer
	// 3) 데이터 타입	int
	DATA* pointer = &a;


	// 함수 
	typedef int(FUNC_TYPE)(int, int);
	//using FUNC_TYPE = int(int, int);	// Modern C++

	// 1) 포인터		*
	// 2) 변수 이름		fn
	// 3) 데이터 타입	함수 (인자는 int, int 반환은 int)
	int (*fn)(int, int);
	//FUNC_TYPE* fn;
	
	fn = Add;

	// 함수의 이름은 함수의 시작 주소 (배열과 유사)
	//int result = Add(1, 2);
	int result = fn(1, 2);		// 기본 문법
	cout << result << endl;

	int result2 = (*fn)(1, 2);	// 함수 포인터는 *(접근 연산자) 붙어도 함수 주소! 
	cout << result << endl;

	Item items[10] = {};
	items[3]._rarity = 3;
	Item* rareItem = FindItem(items, 10, isOwnerItem, 3);

	/*---------------------------------------------------------------------------------*/

	// typedef의 진실
	// typedef 왼쪽 오른값 -> 오른쪽 (커스텀 타입 정의)
	// 정확히는 왼쪽/오른쪽 기준이 아니라,
	// [선언 문법]에서 typedef를 앞에다 붙이는 쪽

	typedef	int INTEGER;
	typedef	int* POINTER;
	typedef	int ARRAY[20];

	typedef	int (*PFUNC)(int, int);		// 일반 함수 포인터


	// 위 문법으로 [전역 함수 / 정적 함수]만 담을 수 있다
	
	// 멤버 함수 포인터
	typedef	int (Knight::*PMEMFUNC)(int, int);		// 멤버 함수 포인터
	PMEMFUNC mfn;
	mfn = &Knight::GetHp;

	Knight k1;
	(k1.*mfn)(1, 2);

	Knight* k2 = new Knight();
	(k2->*mfn)(1, 2);

	delete k2;

	return 0;
}