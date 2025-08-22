#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <set>



int main()
{
	std::pair <int, std::string> frominp;
	std::string input;
	std::set<std::string> setForAnswer;
	std::set<std::pair<int, std::string>> inner;
	std::map <int, std::set<std::string>> answer;
	int page, n;
	std::cin >> n;
	while (n != 0)
	{
		std::cin >> input >> page;// function 2| terminate 2
		frominp.first = page; // 2
		frominp.second = input;// function
		inner.insert(frominp);// [2] [function, terminate] || inner = {{ 2, function}, { 2, terminate}, {3, something}}
		n -= 1;
	}
	if (inner.size() == 1)
	{
		std::cout << inner.begin()->first << ' ' << inner.begin()->second;
	}
	else
	{
		for (auto iter = std::next(inner.begin()); iter != inner.end();)
		{

			//	auto n_iter = std::next(iter);//		
			if (iter->first == std::prev(iter)->first)// если страница одна (не добавило)

			{
				setForAnswer.insert(iter->second);

				setForAnswer.insert(std::prev(iter)->second);
				answer[iter->first] = setForAnswer;
			}
			else if ((iter->first != std::prev(iter)->first) and (std::prev(iter) != inner.begin())) // если различны
			{
				setForAnswer.insert(iter->second); // ТУТ
				answer[iter->first] = setForAnswer;
				setForAnswer.clear();
				/*derivative 10
					function 2
					function 10
					function 10
					limit 7*/
			}
			// Если последний
			else if (std::prev(iter) == inner.begin())
			{
				//
				if (std::prev(iter)->first == iter->first)
				{
					setForAnswer.insert(iter->second);
					setForAnswer.insert(std::prev(iter)->second);
					answer[iter->first] = setForAnswer;
					setForAnswer.clear();
				}
				else
				{
					setForAnswer.insert(std::prev(iter)->second);
					answer[std::prev(iter)->first] = setForAnswer;

					setForAnswer.clear();
					setForAnswer.insert(iter->second);
					answer[iter->first] = setForAnswer;
					setForAnswer.clear();

				}
			}
			std::advance(iter, 1);
		}
	}
	for (const auto& [iter, string] : answer)
	{
		std::cout << iter << ' ';
		for (const auto& str : string)
		{
			std::cout << str << ' ';
		}
		std::cout << '\n';
	}

}
//	std::pair <int, std::string> start = *inner.begin();
// 
// 
// 
// 
// 
// 
// 
// 
//	for (const auto& iner = std::next(inner.begin()); iner != inner.end();) //{ 2, terminate}
//	{
//		std::pair <int, std::string> per = *inner.begin();
//		int prev = 
//		answer[page] = iner.second;
//	}
//
//	for (const auto& [iter, string] : answer)
//	{
//		std::cout << iter << ' ';
//		for (const auto str = string.begin();str != std::prev(string.end());)
//		{
//			std::cout << *str << ' ';
//			std::advance(str, 1);
//		}
//		std::cout << *std::prev(string.end());
//
//	}
//
//}
