#include <iostream>

using namespace std;

// 오늘의 주제 : enum class

// unscoped enum (범위 없는)
enum PlayerType //: char
{
	PT_None,
	PT_Knight = 5,
	PT_Archer,
	PT_Mage,
};

enum MonsterType
{
	MT_None,
};

enum class ObjectType
{
	Player,
	Monster,
	Projectile,
};


int main()
{
	// enum class (scoped enum)
	// 1) 이름공간 관리 (scoped)
	// 2) 암묵적인 변환 금지

	cout << sizeof(PlayerType) << endl;

	double value = PT_Knight;
	double value2 = static_cast<double>(ObjectType::Player);

	int choice;
	cin >> choice;

	//if (choice == PT_Knight)
	if (choice == static_cast<int>(ObjectType::Monster))
	{

	}

	unsigned int bitFlag;
	//bitFlag = (1 << PT_Knight);
	bitFlag = (1 << static_cast<int>(ObjectType::Player));

	return 0;
}