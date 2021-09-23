#include <iostream>
#include <time.h>
using namespace std;

// 오늘의 주제 타입 변환 (포인터)

class Knight
{
public:
	int _hp = 0;
};

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{
		cout << "Item(int)" << endl;
	}

	Item(const Item& item)
	{
		cout << "Item(const Item&)" << endl;
	}

	virtual ~Item()
	{
		cout << "~Item()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Item" << endl;
	}

public:
	int _itemType = 0;
	int _itemDbId = 0;

	char _dummy[4096] = {};		// 이런 저런 정보들로 인해 비대해진 
};

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2,
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON)
	{
		cout << "Weapon()" << endl;
		_damage = rand() % 100;
	}

	virtual ~Weapon()
	{
		cout << "~Weapon()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Weapon" << endl;
	}

public:
	int _damage = 0;
};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor()" << endl;
	}

	virtual ~Armor()
	{
		cout << "~Armor()" << endl;
	}

public:
	int _defence = 0;
};

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{
	item->Test();
}


int main()
{
	// 복습
	//{
	//	// Stack [ type(4) dbid(4) dummy(4096) ]
	//	Item item;

	//	// Stack [ 주소(4 or 8) ] -> Heap [ type(4) dbid(4) dummy(4096) ]
	//	Item* item2 = new Item();

	//	TestItem(item);
	//	TestItem(*item2);

	//	TestItemPtr(&item);
	//	TestItemPtr(item2);

	//	// 메모리 누수(Memory Leak) -> 점점 가용 메모리가 줄어들어 Crash
	//	delete item2;
	//}

	// 배열
	//{
	//	cout << "--------------------------" << endl;

	//	// 진짜 아이템 100개가 있는 것 (스택 메모리에 올라와 있는)
	//	Item item3[100] = {};

	//	cout << "--------------------------" << endl;

	//	// 아이템을 가리키는 바구니가 100개. 실제 아이템이 1개도 없을 수도 있음
	//	Item* item4[100] = {};

	//	for (int i = 0; i < 100; i++)
	//		item4[i] = new Item();

	//	cout << "--------------------------" << endl;

	//	for (int i = 0; i < 100; i++)
	//		delete item4[i];
	//}

	// 연관성이 없는 클래스 사이의 포인트 변환 테스트
	{
		// Stack [ 주소 ] -> Heap [ _hp(4) ]
		Knight* knight = new Knight();
		
		// 암시적으로 NO
		// 명시적으로 OK
		// Stack [ 주소 ]
		//Item* item = (Item*)knight;
		//item->_itemType = 1;
		//item->_itemDbId = 2;

		delete knight;
	}

	// 부모 -> 자식 변환 테스트
	{
		Item* item = new Item();

		//Weapon* weapon = (Weapon*)item;
		//weapon->_damage = 10;

		delete item;
	}

	// 자식 -> 부모 변환 테스트
	{
		Weapon* weapon = new Weapon();

		Item* item = weapon;

		delete weapon;
	}

	Item* inventory[20] = {};

	srand((unsigned int)time(nullptr));

	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2;		// 0 ~ 1
		switch (randValue)
		{
		case 0:
			inventory[i] = new Weapon();
			break;

		case 1:
			inventory[i] = new Armor();
			break;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}
	}

	/* ------------------- 매우 매우 매우 중요 ------------------- */

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		// 부모 클래스의 소멸자에 virtual 붙임으로써 (부모, 자식 virtual 소멸자도 가능)
		// 상속된 모든 클래스를 소멸자를 작동시킨다.
		delete item;
	}


	// [결론]
	// - 포인터 vs 일반 타입 : 차이를 생각하자
	// - 포인터 사이의 타입 변환(캐스팅)을 할 때는 매우 매우 조심해야 한다!
	// - 부모-자식 관계에서 부모 클래스의 소멸자에는 까먹지 말고 virtual을 붙이자!!!

	return 0;
}