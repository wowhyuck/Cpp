#include <iostream>

using namespace std;

// 오늘의 주제 : override, final

class Creature
{
public:
	virtual void Attack()
	{
		cout << "Creature" << endl;
	}
};

class Player : public Creature
{
public:
	virtual void Attack() override
	{
		cout << "Player" << endl;
	}
};


class Knight : public Player
{
public:
	// 재정의 (override)
	virtual void Attack() final
	{
		cout << "Knight" << endl;
	}

private:
	int _stamina = 100;
};


int main()
{
	Player* p = new Knight();
	p->Attack();

	return 0;
}