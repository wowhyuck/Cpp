#include <iostream>
#include <map>
#include <set>
using namespace std;

// 오늘의 주제 : set, multimap, multiset


int main()
{
	// (Key = Value)
	set<int> s;

	// 넣고
	// 빼고
	// 찾고
	// 순회하고

	// 넣고
	s.insert(3);
	s.insert(4);
	s.insert(2);
	s.insert(1);
	s.insert(8);
	s.insert(5);

	// 빼고
	s.erase(4);

	// 찾고
	set<int>::iterator findIt = s.find(5);
	if (findIt == s.end())
	{
		cout << "못 찾음" << endl;
	}
	else
	{
		cout << "찾음" << endl;
	}

	// 순회하고
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << (*it) << endl;
	}

	cout << "-------------------------------" << endl;

	multimap<int, int> mm;

	// 넣고
	mm.insert(make_pair(1, 100));
	mm.insert(make_pair(1, 200));
	mm.insert(make_pair(1, 300));
	mm.insert(make_pair(2, 400));
	mm.insert(make_pair(2, 500));

	//mm[1] = 500;		// 불가능
	
	// 빼고
	//unsigned int count = mm.erase(1);

	// 찾고
	multimap<int, int>::iterator itFind = mm.find(1);
	if (itFind != mm.end())
		mm.erase(itFind);

	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> itPair;
	itPair = mm.equal_range(1);
	
	multimap<int, int>::iterator itBegin = mm.lower_bound(1);
	multimap<int, int>::iterator itEnd = mm.upper_bound(1);

	// 순회하고
	for (multimap<int, int>::iterator it = itPair.first; it != itPair.second; ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	cout << "-------------------------------" << endl;

	multiset<int> ms;

	// 넣고
	ms.insert(100);
	ms.insert(100);
	ms.insert(100);
	ms.insert(200);
	ms.insert(200);

	// 찾고
	multiset<int>::iterator findItms = ms.find(100);

	pair<multiset<int>::iterator, multiset<int>::iterator> itPairms;
	itPairms = ms.equal_range(100);

	multiset<int>::iterator itBeginMs = ms.lower_bound(100);
	multiset<int>::iterator itEndMs = ms.upper_bound(100);

	for (multiset<int>::iterator it = itPairms.first; it != itPairms.second; ++it)
	{
		cout << (*it) << endl;
	}

	return 0;
}