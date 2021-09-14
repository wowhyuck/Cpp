#include <iostream>
using namespace std;

// 오늘의 주제 : 상속성

// 객체지향 (OOP : Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성


// 상속 (Inheritance)

// 메모리 (건물을 쌓아올리는 것처럼)
// [   Knight   ]
// [ [ Player ] ]

// 생성자(N) / 소멸자(1)
// -> Knight를 생성하면 -> Player의 생성자? Knight의 생성자?
// -> 그냥 둘 다 호출하자!

// Example)
// GameObject
// - Creature
// -- Player, Monster, NPC, Pet
// - Projectile
// -- Arrow, Fireball
// - Env

// Item
// - Weapon
// -- Sword, Bow
// - Armor
// -- Helmet, Boots
// - Consumable
// -- Potion, Scroll

class GameObject
{
	int _objectId;
};

class Player : public GameObject
{
public:
	Player()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "Player() 기본 생성자 호출" << endl;
	}

	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Player(int) 생성자 호출" << endl;
	}

	~Player()
	{
		cout << "~Player() 소멸자 호출" << endl;
	}


	void Move() { cout << "Player Move 호출" << endl; }
	void Attack() { cout << "Player Attack 호출" << endl; }
	void Die() { cout << "Player Die 호출" << endl; }

public:
	int _hp;
	int _attack;
	int _defence;
};

// class는 일종의 설계도
class Knight : public Player
{
public :
	Knight()
		/*
		선(먼저)처리 영역
		- 여기서 Player() 생성자를 호출
		*/
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		_stamina = 100;
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	Knight(int stamina) : Player(100)
		/*
		선(먼저)처리 영역
		- 여기서 Player(int) 생성자를 호출
		*/
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		_stamina = stamina;
		cout << "Knight(int) 생성자 호출" << endl;
	}

	~Knight()
	{
		cout << "~Knightr() 소멸자 호출" << endl;
	}
		/*
		후(나중)처리 영역
		- 여기서 ~Player() 소멸자를 호출
		*/

	// 재정의
	void Move() { cout << "Knight Move 호출" << endl; }
public:
	int _stamina;

};

class Mage : public Player
{
public:

public:
	int _mp;
};


int main()
{
	Knight k;
	k._hp = 100;
	k._attack = 10;
	k._defence = 5;
	k._stamina = 50;

	//k.Move();
	//k.Player::Move();

	//k.Attack();
	//k.Die();



	return 0;
}