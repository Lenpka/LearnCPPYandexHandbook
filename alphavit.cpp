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
	std::set<char> setword2(word2.begin(), word2.end());
	for (const auto& chr : setword2)
	{
		if (setword1.find(chr) != setword1.end())
		{
			answer.insert(chr);
		}

	}
	// dataans, ananas -> ans
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

		// первый элемент
		if (count == 1)
		{
			twoWods.first = input;
		}
		// второй
		else if (count == 2)
		{
			twoWods.second = input;
		}
		// если больше, чем 2 слова на входе, то первый 
		else if (count > 2)
		{
			twoWods.first = s;
			s.clear();
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
		for (const auto& iter :std::set(twoWods.first.begin(), (twoWods.first.end())))
		{
			std::cout << iter;
		}
	}
	else
	{
		for (const auto& iter : ans)
		{
			std::cout << iter;
		}
	}
}