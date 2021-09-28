#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 오늘의 주제 : list

// vector : 동적 배열
 
template<typename T>
class Node
{
public:
	Node() : _next(nullptr), _prev(nullptr), _data(T())
	{

	}

	Node(const T& value) : _next(nullptr), _prev(nullptr), _data(value)
	{

	}

public:
	Node*	_next;
	Node*	_prev;
	T		_data;
};

template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr)
	{

	}

	Iterator(Node<T>* node) : _node(node)
	{

	}

	Iterator<T>& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Iterator<T> operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}

	Iterator<T>& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Iterator<T> operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	T& operator*()
	{
		return _node->_data;
	}

	bool operator==(const Iterator& right)
	{
		return _node == right._node;
	}

	bool operator!=(const Iterator& right)
	{
		return _node != right._node;
	}

public:
	Node<T>* _node;
};

// <-> [ header ] <->
// [1] <-> [2] <-> [3] <-> [ header ] <->
template<typename T>
class List
{
public:
	List() : _size(0)
	{
		_header = new Node<T>();
		_header->_prev = _header;
		_header->_next = _header;
	}

	~List()
	{
		while (_size > 0)
			pop_back();

		delete _header;
	}

	void push_back(const T& value)
	{
		AddNode(_header, value);
	}

	void pop_back()
	{
		RemoveNode(_header->_prev);
	}

	Node<T>* AddNode(Node<T>* before, const T& value)
	{
		Node<T>* node = new Node<T>(value);

		Node<T>* prevNode = before->_prev;
		prevNode->_next = node;
		node->_prev = prevNode;

		node->_next = before;
		before->_prev = node;

		_size++;

		return node;
	}

	Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		--size;

		return nextNode;
	}

	int size() { return _size; }

public:
	typedef Iterator<T> iterator;
	iterator begin() { return iterator(_header->_next); }
	iterator end() { return iterator(_header); }

	iterator insert(iterator it, const T& value)
	{
		return iterator(AddNode(it._node, value));
	}

	iterator erase(iterator it)
	{
		Node<T> node = RemoveNode(it._node);
		return iterator(node);
	}

public:
	Node<T>* _header;
	int _size;
};

// 단일 / 이중 / 원형
// list : 연결 리스트


int main()
{
	// list (연결 리스트)
	// - list의 동작 원리
	// - 중간 삽입/삭제 (GOOD / GOOD)
	// - 처음/끝 삽입/삭제 (GOOD / GOOD)
	// - 임의 접근 (NO)

	list<int> li;
	list<int>::iterator itRemember;

	for (int i = 0; i < 100; i++)
	{
		if (i == 50)
		{
			itRemember = li.insert(li.end(), i);
		}
		else
		{
			li.push_back(i);
		}
	}

	//li.push_front(10);
	int size = li.size();
	//li.capacity();		// 없음

	int first = li.front();
	int last = li.back();

	//li[3] = 10;			// 없음

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	int* ptrBegin = &(li.front());
	int* ptrEnd = &(li.back());

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}

	li.insert(itBegin, 100);
	li.erase(li.begin());
	li.pop_front();
	li.remove(10);

	// * 임의 접근이 안된다
	// * 중간 삽입/삭제 빠르다?

	// 50번 인덱스에 있는 데이터 삭제
	//list<int>::iterator it = li.begin();
	//for (int i = 0; i < 50; i++)
	//	++it;

	li.erase(itRemember);

	cout << "--------------------------------" << endl;

	/*---------------------------------------------------------*/

	List<int> li2;
	List<int>::iterator eraseIt;

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			eraseIt = li2.insert(li2.end(), i);
		}
		else
		{
			li2.push_back(i);
		}
	}

	li2.pop_back();

	li2.erase(eraseIt);

	for (List<int>::iterator it = li2.begin(); it != li2.end(); ++it)
	{
		cout << (*it) << endl;
	}

	return 0;
}