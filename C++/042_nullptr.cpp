#include <iostream>

using namespace std;

// 오늘의 주제 : nullptr

class Knight
{
public:
	void Test()
	{

	}


};

Knight* FindKnight()
{
	// TODO

	return nullptr;
}

void Test(int a)
{
	cout << "Test(int)" << endl;
}

void Test(int* ptr)
{
	cout << "Test(int*)" << endl;
}

// NullPtr 구현
const
class
{
public:
	// 그 어떤 타입이 포인터가 와도 치환 가능
	template<typename T>
	operator T* () const
	{
		return 0;
	}
	
	// 그 어떤 타입의 멤버 포인터가 와도 치환 가능
	template<typename C, typename T>
	operator T C::* () const
	{
		return 0;
	}

private:
	void operator&() const;		// 주소값 &을 막는다
} _NullPtr;

int main()
{
	int* ptr = NULL;	// 0 NULL

	// 1) 오동작 방지
	//Test(0);
	//Test(NULL);
	Test(nullptr);

	//Test(NullPtr);

	// 가독성
	auto knight = FindKnight();
	if (knight == nullptr)
	{

	}

	void(Knight:: * memFunc)();
	memFunc = &Knight::Test;
	if (memFunc == _NullPtr)
	{

	}

	nullptr_t whoami = nullptr;

	return 0;
}