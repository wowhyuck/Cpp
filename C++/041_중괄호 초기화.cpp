﻿#include <iostream>
#include <vector>
using namespace std;

// 오늘의 주제 : 중괄호 초기화 { }

class Knight
{
public:
	Knight()
	{

	}

	Knight(int a, int b)
	{
		cout << "Knight(int, int)" << endl;
	}

	Knight(initializer_list<int> li)
	{
		cout << "Knight(Initializer_list)" << endl;
	}
};


int main()
{
	// 중괄호 초기화 { }
	int a = 0;
	int b(0);
	int c{ 0 };

	Knight k1;
	Knight k2 = k1;		// 복사 생성자 (대입 연산자X)
	
	Knight k3{ k2 };

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2(10, 1);

	int arr[] = { 1, 2, 3, 4 };
	vector<int> v3{ 1, 2, 3, 4 };

	// 중괄호 초기화
	// 1) vector 등 container과 잘 어울린다
	vector<int> v3{ 1, 2, 3, 4 };

	// 2) 축소 변환 방지
	int x = 0;
	//double y{ x };		// 허용 X

	// 3) Bonus
	Knight k4{ };		// 기본 생성자 버전

	Knight k5{ 1, 2 };	// -> initializer_list 버전이 우선, Knight(int, int) 생성자가 후순위

	// 괄호 초기화 ()를 기본으로 간다
	// - 전통적인 C++ (거부감이 없음)
	// - vector 등 특이한 케이스에 대해서만 { } 사용

	// 중괄호 초기화 { }를 기본으로 간다
	// - 초기화 문법의 일치화
	// - 축소 변환 방지

	return 0;
}