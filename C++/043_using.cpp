#include <iostream>
#include <list>

using namespace std;

// 오늘의 주제 : using

typedef int id;
using id2 = int;

// 1) 직관성
typedef void (*MyFunc)();
using MyFunc2 = void(*)();

// 2) 템플릿
template<typename T>
using List = std::list<T>;		// typedef는 템플릿 지원 안함 -> 간접적으로 템플릿 사용 (직관성 X)

template<typename T>
struct List2
{
	typedef std::list<T> type;
};


int main()
{
	List<int> li;
	li.push_back(1);

	List2<int>::type li2;

	return 0;
}