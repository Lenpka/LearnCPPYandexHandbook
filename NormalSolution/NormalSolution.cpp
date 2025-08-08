#include <iostream>
#include <string>
#include <vector>

std::vector <std::string> Split(std::string str, char delimiter)
{
	size_t len_str = str.size();
	std::vector <std::string> ans;
	std::string substr = "";
	size_t  start = 0;
	for (size_t i = 0; i <= len_str; i++)
	{

		if ((str[i] == delimiter) or (i == str.length()))
		{
			substr = str.substr(start, i - start);
			start = i + 1;
			ans.push_back(substr);
		}
	}
	return ans;
}
int main()
{
	std::vector<std::string> answer;
	answer = Split("34_24", '_');
	for (size_t j = 0; j < answer.size(); j++)
	{
		std::cout << answer[j] << '\n';
	}
	
}

