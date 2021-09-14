#include <iostream>
using namespace std;

// 오늘의 주제 : 은닉성

// 객체지향 (OOP : Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성

// 은닉성(Data Hiding) = 캡슐화(Encapsulation)
// 몰라도 되는 것을 깔끔하게 숨긴다
// 숨기는 이유?
// - 1) 정말 위험하고 건드리면 안되는 경우
// - 2) 다른 경로로 접근하길 원하는 경우

// public		protected		private
// - public <- 누구나 사용 가능
// - protected <- 상속받은 클래스만 사용 가능
// - private <- class Car 내부에서만 사용 가능

// 상속 접근 지정자 : 부모한테 받은 상속을 다음 자식한테 상속을 어떻게 물려주지?
// 부모님한테 물려받은 상속을 꼭 나의 자식들한테도 똑같이 물려줘야 하지 않음
// - public : 공개적 상속 -> 부모님의 상속을 설계 그대로 (public -> public, protected -> protected)
// - protected : 보호받는 상속 -> 내 자식들한테만 물려줌 (public -> protected, protected -> protected)
// - private : 개인적인 상속 -> 자식들한테 상속 안함 (public -> private, protected -> private)

class Car
{
public:		// (멤버) 접근 지정자
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}
	void TurnKey()
	{
		// ...
		void RunEngine();
	}

protected:
	void DisassembleCar() {}
	void RunEngine() {}
	void ConnectCircuit() {}

private:
	// 멤버 변수
};

class SuperCar : public Car		// 상속 접근 지정자
{
public:
	void PushRemoteController()
	{
		// ...
		void RunEngine();
	}
};

class TestSuperCar : SuperCar
{
public:
	void Test()
	{
		DisassembleCar();
	}
};


// '캡슐화'
// 연관된 데이터와 함수를 논리적으로 묶어놓은 것
class Berserker
{
public:

	int GetHp() { return _hp; }

	// 사양 : 체력이 50 이하로 떨어지면 버서커 모드 발동 (강해짐)
	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}

private:
	void SetBerserkerMode()
	{
		cout << "매우 강해짐" << endl;
	}

private:
	int _hp = 100;
};


int main()
{
	Car car;
	
	Berserker b;
	b.SetHp(20);

	SuperCar sc;

	return 0;
}