#include <iostream>
#include <map>
#include <string>
#include <unordered_set>
#include <set>
#include <utility>

//функция сравнения двух контейнеров
std::set<char> ret(const std::string& word1, const std::string& word2)
{
	std::set<char> setword1 (word1.begin(), word1.end());
	std::set<char> answer;
	for (const auto& chr : word2)
	{
		if (setword1.find(chr) != setword1.end())
		{
			answer.insert(chr);
		}

	}
	return answer;
}



int main()
{
	//	std::map <char, int> counter;
	std::set <char> ans;
	int count = 0;
	std::string  input;
	std::pair <std::string, std::string> twoWods = { "", "" };
	std::string s;



	while (std::getline(std::cin, input))
	{
		//Пустые элементы
		if (input == "")
		{	
			ans = {};
		}
		count += 1;


		if (count == 1)
		{
			twoWods.first = input;
		}
		else if (count == 2)
		{
			twoWods.second = input;
		}
		else if (count > 2)
		{
			twoWods.first = s;
			twoWods.second = input;
		}

		ans = ret(twoWods.first, twoWods.second);
		for (auto const& str : ans)
		{
			s += str;
		}

				
	}
	if (count == 1)
	{
		for (const auto& iter :std::set(twoWods.first.begin(), std::prev(twoWods.first.end())))
		{
			std::cout << iter << '\n';
		}
	//std :: cout <<	twoWods.first[twoWods.first.size()-1];
	}
	else
	{
		for (const auto& iter : ans)
		{
			std::cout << iter;
		}
	}
}