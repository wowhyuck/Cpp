#include <iostream>
using namespace std;

// 오늘의 주제 : 함수 마무리

// 오버로딩 (중복 정의 : 함수 이름의 재사용)
// - 매개변수 갯수가 다르거나
// - 매개변수 타입이 다르거나 (순서가 다른 것도 포함)

int Add(int a, int b)
{
	int result = a + b;
	return result;
}

float Add(float a, float b)
{
	float result = a + b;
	return result;
}

// 기본 인자값
void SetPlayerInfo(int hp, int mp, int attack, int guildId = 0, int castleId = 0)
{

}

// 스택 오버플로우
int Factorial(int n)
{
	if (n <= 1)
		return 1;

	return n * Factorial(n - 1);
}


int main()
{
	// 오버로딩
	//int result = Add(1, 2);
	//float result = Add(1.5f, 2.5f);

	//cout << result << endl;


	// 기본 인자값
	//SetPlayerInfo(100, 40, 10);


	// 스택 오버플로우
	// 5! = 5 * 4 * 3 * 2 * 1
	//int result = Factorial(5);
	int result = Factorial(1000000);
	cout << result << endl;

	return 0;
}