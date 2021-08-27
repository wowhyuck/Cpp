#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터



int main()
{
	// TYPE* 변수이름;
	// 일단 2가지 요소
	// - TYPE
	// - *
	// 참고) 포인터의 크기는 4바이트(32비트) or 8바이트(64비트) 고정 크기
	int number = 1;
	int* ptr = &number;

	// 추가 문법 : [주소를 저장한 포인터 변수]가 가리키는 주소로 가서 무엇을 해라!
	// *변수 이름 = 값;

	int value1 = *ptr;
	*ptr = 2;

	// * 사용 지점에 따라서 구분
	// - 변수 선언 (주소를 저장하는 용도)
	// - 사용할 때 (해당 주소를 타고 순간이동)

	// TYPE은 왜 붙여줄까?
	// * = 포인터의 의미 = 주소를 저장하는 바구니 = 4 or 8 바이트 고정 크기
	// 주소가 저장된 바구니에 무엇이 저장되어있는지 알려줌
	

	// 타입의 불일치
	// 밀려나서 메모리를 덮게됨
	__int64* ptr2 = (__int64*)&number;
	*ptr2 = 0x0000AABBCCDDEEFF;


	int hp = 1;
	SetHp(&hp);

	return 0;
}

void SetHp(int* hp)
{
	*hp = 100;
}