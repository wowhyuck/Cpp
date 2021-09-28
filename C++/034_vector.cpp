#include <iostream>
#include <vector>
using namespace std;

// 오늘의 주제 : vector

template<typename T>
class Iterator
{
public:
	Iterator() : _ptr(nullptr)
	{

	}

	Iterator(T* ptr) : _ptr(ptr)
	{

	}

	Iterator operator+(const int count)
	{
		Iterator temp = *this;
		temp._ptr += count;
		return temp;
	}

	Iterator operator-(const int count)
	{
		Iterator temp = *this;
		temp._ptr -= count;
		return temp;
	}

	Iterator& operator++()
	{
		_ptr++;
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator temp = *this;
		_ptr++;
		return temp;
	}

	Iterator& operator--()
	{
		_ptr--;
		return *this;
	}

	Iterator operator--(int)
	{
		Iterator temp = *this;
		_ptr--;
		return temp;
	}

	bool operator==(const Iterator& right)
	{
		return _ptr == right._ptr;
	}

	bool operator!=(const Iterator& right)
	{
		return !(*this == right);
	}

	T& operator*()
	{
		return *_ptr;
	}

public:
	T* _ptr;
};

template<typename T>
class Vector
{
public:
	Vector() : _data(nullptr), _size(0), _capacity(0)
	{

	}

	~Vector()
	{
		if (_data != nullptr)
			delete[] _data;
	}


	void push_back(const T& val)
	{
		if (_size == _capacity)
		{
			// 증설 작업
			int newCapacity = static_cast<double>(_capacity * 1.5);

			if (newCapacity == _capacity)
				++newCapacity;

			reserve(newCapacity);
		}

		// 데이터 저장
		_data[_size] = val;

		// 데이터 개수 증가
		++_size;
	}

	void reserve(int capacity)
	{
		_capacity = capacity;

		T* newData = new T[_capacity];

		// 데이터 복사
		for (int i = 0; i < _size; i++)
			newData[i] = _data[i];

		// 기존에 있던 데이터를 날린다
		if (_data)
			delete[] _data;

		// 교체
		_data = newData;
	}

	T& operator[](const int pos) { return _data[pos]; }


	int size() { return _size; }
	int capacity() { return _capacity; }

public:
	typedef Iterator<T> iterator;

	void clear() { _size = 0; }
	iterator begin() { return iterator(&_data[0]); }
	iterator end() { return begin() + _size; }

private:
	T* _data;
	int _size;
	int _capacity;
};


int main()
{
	// STL (Standard Template Library)
	// 프로그래밍할 때 필요한 자료구조/알고리즘들을
	// 템플릿으로 제공하는 라이브러리

	// 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조 : Data Structure)

	// vector (동적 배열)
	// - vector의 동작 원리 (size/capacity)
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	// 동적 배열
	// 매우 매우 중요한 개념 -> 어떻게 배열을 '유동적으로' 사용한 것인가?

	// 1) (여유분을 두고) 메모리를 할당한다
	// 2) 여유분까지 꽉 찼으면, 메모리를 증설한다

	// Q1) 여유분은 얼만큼 적당할까?
	// Q2) 증설을 얼만큼 해야 할까?
	// Q3) 기존의 데이터를 어떻게 처리할까?

	vector<int> v(1000, 0);
	vector<int> v1 = v;

	// size (실제 사용 데이터 개수)
	// capacity (여유분을 포함한 용량 개수)

	//v.resize(1000);		// size 데이터 개수 설정
	//v.reserve(1000);		// capacity 용량 설정

	for (int i = 0; i < 1000; i++)
	{
		v.push_back(100);
		cout << v.size() << " " << v.capacity() << endl;
	}

	v.front();
	v.back();
	v.pop_back();

	v.clear();
	//vector<int>().swap(v);
	cout << v.size() << " " << v.capacity() << endl;

	cout << "----------------------------------" << endl;
	/*-----------------------------------------------------------------------*/

	// 반복자(Iterator) : 포인터와 유사한 개념, 컨테이너의 원소[데이터]를 가리키고, 다음/이전 원소로 이동 가능

	vector<int> v2(10);

	v2.reserve(1000);

	for (vector<int>::size_type i = 0; i < v2.size(); i++)
		v2[i] = i;

	//vector<int>::iterator it;
	//int* ptr;

	//it = v2.begin();
	//ptr = &v2[0];

	//cout << (*it) << endl;
	//cout << (*ptr) << endl;

	//it++;
	//++it;
	//ptr++;
	//++ptr;

	//it--;
	//--it;
	//ptr--;
	//--ptr;

	//it += 2;
	//it = it - 2;
	//ptr += 2;
	//ptr = ptr - 2;

	vector<int>::iterator itBegin = v2.begin();
	vector<int>::iterator itEnd = v2.end();

	// 더 복잡해보이는데 iterator 쓰는 이유
	// 다른 컨테이너는 v[i]와 같은 인덱스 접근이 안 될 수도 있음
	// iterator는 vector뿐 아니라, 다른 컨테이너에도 공통적으로 있는 개념
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
	{
		cout << (*it) << endl;
	}

	int* ptrBegin = &v2[0];		// v2.begin()._Ptr;
	int* ptrEnd = ptrBegin + 10;	// v2.end()._Ptr;
	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
	{
		cout << (*ptr) << endl;
	}

	// const int*
	//vector<int>::const_iterator cit = v2.cbegin();

	for (vector<int>::reverse_iterator it = v2.rbegin(); it != v2.rend(); ++it)
	{
		cout << (*it) << endl;
	}

	cout << "----------------------------------" << endl;
	/*-----------------------------------------------------------------------*/

	// - 중간 삽입/삭제 (BAD)
	// - 처음/끝 삽입/삭제 (BAD / GOOD)
	// - 임의 접근 (Random Access)

	// vector = 동적 배열 = 동적으로 커지는 배열 = 배열
	// 원소가 하나의 메모리 블록에 연속하게 저장된다

	//v2.push_back(1);
	//v2.pop_back();

	//v2[3] = 2;

	//vector<int>::iterator insertIt = v2.insert(v2.begin() + 2, 5);
	//vector<int>::iterator eraseIt1 = v2.erase(v2.begin() + 2);
	//vector<int>::iterator eraseIt2 = v2.erase(v2.begin() + 2, v2.begin() + 4);

	// 쭉~ 스캔하면서, 3이라는 데이터가 있으면 일괄 삭제하고 싶다
	for (vector<int>::iterator it = v2.begin(); it != v2.end();)
	{
		int data = 3;
		if (data == 3)
		{
			it = v2.erase(it);
		}
		else
			++it;
	}

	cout << "----------------------------------" << endl;
	/*-----------------------------------------------------------------------*/

	Vector<int> v3;

	//v3.reserve(100);

	for (int i = 0; i < 100; ++i)
	{
		v3.push_back(i);
		cout << v3.size() << " " << v3.capacity() << endl;
	}

	for (int i = 0; i < v3.size(); ++i)
	{
		cout << v3[i] << endl;
	}

	cout << "----------------------------------" << endl;

	for (Vector<int>::iterator it = v3.begin(); it != v3.end(); ++it)
	{
		cout << (*it) << endl;
	}

	return 0;
}