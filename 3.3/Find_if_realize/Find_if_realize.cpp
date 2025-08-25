#include <iostream>
#include <set>
template <typename Iter, typename Predicate>
int fin_if(Iter begin, Iter end, Predicate func)
{
	int ret = 0;
	while (begin != end)
	{
		if (func(*begin) == 1)
		{
			return ret;
		}
		++begin;
		ret += 1;

	}
	return ret;
}

int main()
{
	std::set<int> test = { 1 , 2, 3, 4, 5 };
	std::cout << fin_if(test.begin(), test.end(), [](int i)->bool {return i > 3; });
}