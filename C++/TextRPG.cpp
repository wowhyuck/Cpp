#include <iostream>
#include <time.h>
using namespace std;

// 오늘의 주제 : TextRPG

enum PlayerTpye
{
	PT_Kight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

int playerType;
int hp;
int attack;
int defence;

int monsterType;
int monsterHp;
int monsterAttack;
int monsterDefence;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();

int main()
{
	// 랜덤 시드 설정
	srand(time(0));
	EnterLobby();



	return 0;
}


void EnterLobby()
{
	while (true)
	{
		cout << "--------------------" << endl;
		cout << "로비에 입장했습니다." << endl;
		cout << "--------------------" << endl;

		// 플레이어 직업 선택
		SelectPlayer();


		cout << "----------------------------" << endl;
		cout << "(1) 필드 입장  (2) 게임 종료" << endl;
		cout << "----------------------------" << endl;
		cout << "> ";

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterField();
		}
		else
		{

		}

	}

}

void SelectPlayer()
{
	while (true)
	{
		cout << "----------------------------" << endl;
		cout << "직업을 골라주세요." << endl;
		cout << "(1) 기사  (2) 궁수  (3) 법사" << endl;
		cout << "----------------------------" << endl;
		cout << "> ";

		cin >> playerType;

		if (playerType == PT_Kight)
		{
			cout << "기사 생성중... !" << endl;
			hp = 150;
			attack = 10;
			defence = 5;
			break;
		}
		else if (playerType == PT_Archer)
		{
			cout << "궁수 생성중... !" << endl;
			hp = 100;
			attack = 15;
			defence = 3;
			break;
		}
		else if (playerType == PT_Mage)
		{
			cout << "법사 생성중... !" << endl;
			hp = 80;
			attack = 25;
			defence = 0;
			break;
		}
	}
}

void EnterField()
{
	while (true)
	{
		cout << "--------------------" << endl;
		cout << "필드에 입장했습니다." << endl;
		cout << "--------------------" << endl;

		cout << "[PLAYER] HP : " << hp << " / ATT : " << attack << " / DEF : " << defence << endl;

		CreateRandomMonster();
	}
}

void CreateRandomMonster()
{
	// 1 - 3
	monsterType = 1 + (rand() % 3);


}