#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 vs 참조

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

StatInfo globalInfo;

void PrintInfoByPtr(StatInfo* info)
{
	if (info == nullptr)
		return;

	cout << "----------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "----------------" << endl;

	// const 위치
	// * 뒤에 붙인다면?
	// StatInfo* const info
	// info라는 바구니의 내용물(주소)을 바꿀 수 없음
	// info는 주소값을 갖는 바구니 -> 이 주소값이 고정

	// * 앞에 붙인다면?
	// const StatInfo* info
	// info가 '가리키고 있는' 바구니의 내용물을 바꿀 수 없음
	// '원격' 바구니의 내용물을 바꿀 수 없음

	info = &globalInfo;
	info->hp = 10000;
}

void PrintInfoByRef(const StatInfo& info)
{
	cout << "----------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "----------------" << endl;
}


#define OUT
void ChangeInfo(OUT StatInfo& info)
{
	info.hp = 10000;
}

int main()
{
	StatInfo info;
	CreateMonster(&info);

	// 포인터 vs 참조
	// 성능 : 똑같음!
	// 편의성 : 참조 승!

	// 1) 편의성 관련
	// 편의성이 좋다는게 꼭 장점만은 아니다.
	// 포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줄 수 있는데
	// 참조는 자연스럽게 모르고 지나칠 수 있음!
	// ex) 마음대로 고치면?
	// const를 사용해서 마음대로 고치는 부분 개선 가능

	// 참고로 포인터도 const를 사용 가능
	// * 기준으로 앞, 뒤에 붙이느냐에 따라 의미가 다름

	// 2) 초기화 여부
	// 참조 타입은 바구니의 2번째 이름 부여
	// -> 참조하는 대상이 없으면 안됨
	// 반면 포인터는 어떤~ 주소라는 의미
	// -> 대상이 실존하지 않을 수도 있음
	// 포인터에서 '없다'는 의미로? nullptr

	StatInfo* pointer = nullptr;
	pointer = &info;
	PrintInfoByPtr(pointer);

	StatInfo& reference = info;
	PrintInfoByRef(info);

	// 결론은?
	// 사실 Team By Team... 정해진 답은 없다
	// ex) 구글에서 만든 오픈소스를 보면 거의 무조건 포인터 사용
	// ex) 언리얼 엔진에선 reference도 애용

	// Rookiss 선호 스타일)
	// - 없는 경우도 고려해야 한다면 pointer (null 체크 필수)
	// - 바뀌지 않고 읽는 용도(readonly)만 사용하면 const ref&
	// - 그 외 일반적으로 ref (명시적으로 호출할 때 out을 붙인다)
	// -- 단, 다른 사람이 pointer를 만들어놓은걸 이어서 만든다면, 계속 pointer (섞어서 사용하지 않는다)
	ChangeInfo(OUT info);

	// Bonus) 포인터로 사용하던걸 참조로 넘겨주려면?
	PrintInfoByRef(*pointer);

	// Bonus) 참조로 사용하던걸 포인터로 넘겨주려면?
	PrintInfoByPtr(&reference);

	return 0;
}