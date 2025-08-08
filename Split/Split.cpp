#include <iostream>
#include <vector>
#include <string>

std::vector <std::string> Split(const std::string& str, char delimiter)
{
	std::vector <std::string> answer;
	std::string strin;
	int start_index = 0;

	for (size_t i = 1; i <= str.size(); i++)
	{
		if ((str[i] == delimiter) or (i == str.size()))
		{
			strin = str.substr(start_index, i - start_index);
			start_index = i + 1;
			answer.push_back(strin);
		}
	}
	if (answer[0][0] == delimiter)
	{
		answer[0][0] = ' ';
	}

	if ((answer.back() == "") and (answer.size() > 1))
	{
		answer.pop_back();
		answer.back().push_back(' ');
	}
	if ((answer.back() == "") and (answer.size() == 1))
		answer = { "" };
	return answer;
}
int main()
{
		std::vector <std::string> ans = Split("", '-');
	for (size_t j = 0; j < ans.size(); j++) {
			std::cout << ans[j] << '\n';
	};
}
