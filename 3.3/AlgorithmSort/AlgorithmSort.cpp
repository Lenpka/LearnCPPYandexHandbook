#include <iostream>
#include <list>
template <typename Iter, typename Value>
int coun(Iter first, Iter last,const Value& value) // iterator is easy to copy
{
	int ret = 0;
	for (Iter i = first; i != last; ++i)
	{
		if (*i == value)
		{
			++ret;
	}
	}
	return ret;

}


int main()
{
	std::list <int> test = { 1, 2, 3, 3, 3, 4, 5, 3, 1 };
	std::cout << coun(test.begin(), test.end(), 3);


}
//int main()
//{
//	return 0;
//}