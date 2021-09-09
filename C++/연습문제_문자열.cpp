#include <iostream>
using namespace std;

// 오늘의 주제 : 연습문제

// 문제 1) 문자열 길이를 출력하는 함수
int StrLen(const char* str)
{
	// str이라는 문자열의 길이를 반환
	int len = 0;
	char a = *str;

	while (a != '\0')
	{
		len++;
		a = *(str + len);
	}

	return len;
}

// 문제 2) 문자열 복사 함수
#pragma warning(disable : 4996)
char* StrCpy(char* dest, char* src)
{
	//int count = strlen(src);

	//for (int i = 0; i < count; i++)
	//{
	//	dest[i] = src[i];
	//}

	//dest[count] = '\0';

	//return dest;


	char* ret = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return ret;
}

// 문제 3) 문자열 덧붙이는 함수
char* StrCat(char* dest, char* src)
{
	//int count = strlen(dest);
	//int index = 0;

	//while (src[index] != '\0')
	//{
	//	dest[count + index] = src[index];
	//	index++;
	//}

	//dest[count + index] = '\0';

	//return dest;


	char* ret = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return ret;
}

// 문제 4) 두 문자열을 비교하는 함수
int StrCmp(char* a, char* b)
{
	int i = 0;

	while (*a == *b )
	{
		if (*a == '\0' || *b == '\0')
			break;

		a++;
		b++;
	}

	i = *a - *b;

	if (i > 0)
		i = 1;
	else if (i < 0)
		i = -1;

	return i;
}

// 문제 5) 문자열을 뒤집는 함수 (위의 4개 문제는 필수, 이 문제는 연습)
void ReverseStr(char* str)
{
	int start = 0;
	int end = strlen(str) - 1;

	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		start++;
		end--;
	}
}

int main()
{
	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "abcde";
	char b[BUF_SIZE] = "Hella";

	// 문제 1
	//int len = strlen(a);
	//int len = StrLen(a);
	//cout << len << endl;


	// 문제 2
	//strcpy(b, a);
	//strcpy_s(b, a);
	//StrCpy(b, a);


	// 문제 3
	//strcat(a, b);
	//StrCat(a, b);


	// 문제 4
	//int value = strcmp(a, b);
	//int value = StrCmp(a, b);
	//cout << value << endl;


	// 문제 5
	ReverseStr(a);
	cout << a << endl;

	return 0;
}