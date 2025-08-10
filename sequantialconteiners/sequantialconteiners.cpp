#include <iostream>
#include <deque> // learn deque
#include <list>
#include <vector>
template<typename T>
struct Nodes
{
	T value;
	Nodes* node1;
	Nodes* node2;
};
int main()
{
	std::deque<int> doubleendedque = { 1, 2, 3 };
	std::cout << sizeof(doubleendedque) << '\n';
	std::deque <int>& red = doubleendedque;

	red[0] += 1;
	for (size_t test = 0; test < doubleendedque.size(); test++)
	{
		std::cout << red[test] << '\n';
	}
	red.push_front(-1);
	for (int i = 0; i < 30; i++)
	{
		red.push_front(i);
	}
	for (size_t test = 0; test < doubleendedque.size(); test++)
	{
		std::cout << doubleendedque[test];
	}

	
	std::cout << '\n' << sizeof(doubleendedque) << '\n'<<'\n';
	// LIST and NODES
	
	std::list<int> lis = { 1,2,3 };
	for (int x : lis)
	{
		std::cout << x << '\n';
	}
	std::list<int>::iterator iter = lis.begin();
	std::cout << *iter << ' ';
	++iter;
	std::cout << *iter << '\n';
	//test integer and iter(s)
	std::cout << " Testing integer output of list - not working. Only iterator \n";
	for (size_t i = 0; i < lis.size(); i++)
	{
		//std::cout << lis[i]; error
	}
	for (auto iter = lis.begin(); iter != lis.end(); ++iter)
	{
		std::cout << *iter << " and without * (with &) :" << &iter<< '\n';
	}
	auto iteration = lis.begin();//1
	iteration++;//2
	lis.insert(iteration, 5);
	// Delete n%2==0 elements
	for (auto iter = lis.begin(); iter != lis.end();)
		if (*iter % 2 == 0) 
		{
			iter = lis.erase(iter);
		}
		else
		{
 			iter++;

		}
	std::cout << '\n' << "Now functions advance and next";
	auto it = std::next(lis.begin());
	std::cout << '\n' << *it << '\n';
	std::cout << " Now we gona make a error with pointers, linkers and iterators of links to {10, 11, 12, 13} \n";
	std::vector <int> test = { 10, 11, 12 ,13 };
	std :: vector <int> :: iterator itt = test.begin(); // iterator
	int* ptr = &test.front(); //pointer
	int& ref = test.front(); //link
	std::cout << *itt << ' ' <<  *ptr << ' ' << ref << '\n';
	test.push_back(3);
	std::cout << *itt << ' ' << *ptr << ' ' << ref;


}