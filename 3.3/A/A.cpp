#include <iostream>
#include <algorithm>
#include <unordered_set>
template <typename Iter>
Iter Uniqu(Iter first, Iter last) 
{
	using ValueType = typename std::iterator_traits <Iter> ::value_type;
	if (first == last)
	{
		return last;
	}
	
	std::unordered_set<ValueType> templ;
	//int lenCycle = static_cast<int>(std::distance(first, last));
	Iter it = first;// Допустим 8
	for (Iter i = first; i != last; ++i)
	{
		auto what = templ.insert(*i);
		auto how = what.second;
		if (how)
		{
			*it = std::move(*i);
			++it;

		}
		
	}
	return it;

	//std
	////arr = std::copy(first, last, std::next(last));	
	//bool flag = false;
	//while (first != last)
	//{
	//	int start = 1; int counter = 0;
	//	for (int n = 1; *first == *(first + n); n++)
	//	{
	//		++counter;
	//	}


	//	++first;
	//}

int main()
{
	std::vector <int> test {5, 3, 3, 5, 5, 2, 1, 9};
	std::cout << *Uniqu(test.begin(), test.end());
}