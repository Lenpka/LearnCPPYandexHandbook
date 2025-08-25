#include <iostream>
#include <map>
#include <vector>
#include <set>	
#include <utility>
#include <vector>
template <typename Iter>
void revers(Iter first, Iter end)
{
	while (first != end)
	{
		--end;
		if (first == end)
		{
			break;
		}
	
		
			std::swap(*first, *end);
			++first;
		
	}

}


int main()
{
	std::set <char> testSet = { 'a', 'a', 'b', 'b' }; //error
	/*revers(testSet.begin(), testSet.end());
	for (auto i = testSet.begin(); i != testSet.end(); i++)
	{
		std::cout << *i << '\n';
	}*/
	std::vector<int> testVector = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	revers(testVector.begin(), testVector.end());
	for (auto i = testVector.begin(); i != testVector.end(); i++)
	{
		std::cout << *i << '\n';
	}


}