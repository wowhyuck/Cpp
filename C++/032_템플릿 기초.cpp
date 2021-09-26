﻿#include <iostream>
using namespace std;

// 오늘의 주제 : 템플릿 기초

class Knight
{
public:
	// ...

public:
	int _hp = 100;
};

template<typename T>
//template<class T>
void Print(T a)
{
	cout << a << endl;
}

// 템플릿 특수화
template<>
void Print(Knight a)
{
	cout << "Knight !!" << endl;
	cout << a._hp << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

// 연산자 오버로딩 (전역함수 버전)
ostream& operator<<(ostream& os, const Knight& k)
{
	os << k._hp;
	return os;
}

/*-----------------------------------------------------*/

// typename T를 붙이면 '조커카드' (어떤 타입도 다 넣을 수 있음)
// 그런데 무조건 typename을 붙여야 하는 것은 아니다
// template< > 안에 들어가는건 [골라줘야 하는 목록]이라고 할 수 있음
template<typename T, int SIZE>
class RandomBox
{
public:
	T GetRandomData()
	{
		int idx = rand() % SIZE;
		return _data[idx];
	}

public:
	T _data[SIZE];
};

// 템플릿 특수화
template<int SIZE>
class RandomBox<double, SIZE>
{
public:
	double GetRandomData()
	{
		cout << "Random Box Double" << endl;
		int idx = rand() % SIZE;
		return _data[idx];
	}

public:
	double _data[SIZE];
};

int main()
{
	// 템플릿 : 함수나 클래스를 찍어내는 틀
	// 1) 함수 템플릿
	// 2) 클래스 템플릿

	Print(1);
	Print(5.0f);
	Print<int>(5);
	Print("Hello World");

	Print("Hello", 100);

	int result1 = Add(1, 2);
	float result2 = Add<float>(1.1f, 2.2f);

	Knight k1;
	Print(k1);

	/*-----------------------------------------------------*/

	srand(static_cast<unsigned int>(time(nullptr)));
	
	RandomBox<int, 10> rb1;
	for (int i = 0; i < 10; i++)
	{
		rb1._data[i] = i;
	}
	int value1 = rb1.GetRandomData();
	cout << value1 << endl;

	RandomBox<double, 20> rb2;
	for (int i = 0; i < 20; i++)
	{
		rb2._data[i] = i + 0.5;
	}
	int value2 = rb2.GetRandomData();
	cout << value2 << endl;

	return 0;
}