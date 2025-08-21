#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>

//void operator<<(std::unordered_set<char> inp)
//{
//	for (auto& i = inp.begin(); i != inp.end(); i++) {
//		std::cout << i << '\n';
//	}
//}


int main()
{
//	std::map <char, int> counter;
	std::set <char> coun;
	std::vector<std::pair<std::set<char>, size_t>> contCont;
	std::vector <char> answer;
	std::string input;
	std::set <char> alphavit;
	short int count{ 0 }; size_t minlen{ 10000 };
	while (std::getline(std::cin, input))
	{
		if (input == "")
		{
			break;
		}
		for (size_t i = 0; i < input.size(); i++)
		{
			//	counter[input[i]] += 1;
			coun.insert(input[i]); //a,b,c
		}
		if (minlen >= coun.size())
		{
			minlen = coun.size();
		}

	
		if (count <=0)
		{
			alphavit = coun;
			count += 1;
		}

		else
		{
			count += 1;
			std::set<char>::iterator st = coun.begin();

			if (count <= 2)
			{
				answer.clear();
				for (size_t j = 0; j < alphavit.size(); j++)
				{

					if (alphavit.find(*st) != alphavit.end())
					{

						answer.push_back(*st);
					}
					std::advance(st, 1);
				}
			}
			else if (count > 2)
			{
				for (size_t j = 0; j < minlen; j++)
				{

					if ((alphavit.find(*st) != alphavit.end()) and (count > 2))
					{
						answer.clear();

						answer.push_back(*st);
					}
				}
			}
		}

	/*	contCont.push_back({ coun , coun.size()});
		for (const auto& j: coun)
		{
			std::cout << j << '\n';
		}*/

	}
	for (const auto& iter:answer)
	{
		std::cout << iter << '\n';
		
	}
}