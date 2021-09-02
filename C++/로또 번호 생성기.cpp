#include <iostream>
#include <time.h>
using namespace std;

// 오늘의 주제 : 로또 번호 생성기

void Swap(int& a, int& b);
void Sort(int* numbers, int count);
void ChooseLotto(int* numbers);

int main()
{
	// 1) Swap 함수 만들기
	int a = 1;
	int b = 2;
	Swap(a, b);
	cout << a << " " << b << endl;

	// 2) 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
	int numbers[6] = { 1,42,3,15,5,6 };
	int count = sizeof(numbers) / sizeof(int);
	Sort(numbers, sizeof(numbers) / sizeof(int));

	// 3) 로또 번호 생성기
	ChooseLotto(numbers);
	for (int i = 0; i < count; i++)
		cout << numbers[i] << " ";

	return 0;
}


void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Sort(int* numbers, int count)
{
	for (int i = 0; i < count - 1; i++)
	{
		int index = i;

		for (int j = i + 1; j < count; j++)
		{
			if (numbers[index] > numbers[j])
				index = j;
		}

		if (index != i)
			Swap(numbers[i], numbers[index]);
	}
}

void ChooseLotto(int* numbers)
{
	srand((unsigned)time(0));	// 랜덤 시드 설정

	int count = 0;
	while (count != 6)
	{
		int num = (rand() % 45) + 1;
		bool isExist = false;

		for (int i = 0; i < count; i++)
		{
			if (num == numbers[i])
			{
				isExist = true;
				break;
			}
		}

		if (!isExist)
		{
			numbers[count] = num;
			count++;
		}
	}
	
	Sort(numbers, count);
}