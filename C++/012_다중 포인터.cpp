#include <iostream>
using namespace std;

// 오늘의 주제 : 다중 포인터

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char* a)
{
	a = "Bye";
}

void SetMessage(const char** a)
{
	*a = "Bye";
}

int main()
{
	int a = 0;
	SetNumber(&a);
	//cout << a << endl;

	const char* msg = "Hello World";
	SetMessage(msg);
	//cout << msg << endl;

	// .rdata Hello주소[H][e][l][l][o][\0] << 1바이트(char)
	// msg[ Hello주소 ] << 8바이트(주소크기)
	// pp[ &msg ] << 8바이트(주소크기)
	const char** pp = &msg;
	SetMessage(pp);
	cout << msg << endl;

	return 0;
}