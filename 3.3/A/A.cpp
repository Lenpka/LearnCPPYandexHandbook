#include <iostream>
#include <algorithm>
#include <vector>
template <typename ContainerValue>
void Duplicate(std::vector<ContainerValue>& into)
{
	into.resize(into.size() * 2);
	auto first = into.begin();
	auto firstEnd = (into.end()) - into.size() / 2;
	auto ended = (into.end()) - into.size() /2;
	while (first != firstEnd)
	{
		*ended = *first;
		++first;
		++ended;
	}

}


int main()
{
	std::vector<int> test = {1, 2, 3};
	Duplicate(test);
	for (const auto& it : test)
	{
		std::cout << it << '\n';
	}

}