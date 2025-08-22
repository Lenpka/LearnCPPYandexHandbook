#include <string>
#include <iostream>
#include <map>
#include <set>
#include <vector>

std::set<std::string> delim(std::string inp)
{
	std::set <std::string> ans;
	for (size_t i = 0; i < inp.size(); i++)
	{
		if (inp[i] == '/')
		{
			ans.insert(inp.substr(0, i+1));
		}
	}
	return ans;
}

int main()
{
	std::string input;
	std::set <std::string> settingAns;
	while (std::getline(std::cin, input))
	{
		std::set <std::string> ans;

		ans = delim(input);
		for (const auto& ansstr : ans)
		{
			settingAns.insert(ansstr);
		}

	}
	for (const auto& iter : settingAns)
	{
		std::cout << iter << '\n';
	}

}