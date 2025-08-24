#include <iostream>
#include <list>
template <typename Iter, typename Value>
int fin(Iter first, Iter end, Value value)
{
	int ret{ 0 };
	while (first != end)
	{
	
		if (*first == value)
		{
			
			return ret;
		}
		else
		{
			ret += 1;
		}
		++first;
	}
	return ret;


}

int main()

{
	std::list<int> ls{ {1,2,3,4,5} };
	std::cout << fin(ls.begin(), ls.end(),3);

}