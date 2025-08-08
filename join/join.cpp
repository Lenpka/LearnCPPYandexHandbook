#include <iostream>
#include <vector>
#include <string>

std::string Join(std::vector<std::string> tokens, char delimiter)
{
	const size_t size = tokens.size();
	std::string ans = "";
	if (size == 0)
	{
		return "";
	}
	else if (size == 1)
	{
		return tokens[0];
	}
		for (size_t i = 0; i < size-1; i++)
		{

			ans.append(tokens[i] + delimiter);
		}
		ans.append(tokens[size-1]);
		
	return ans;
}

int main()
{
	std::cout << Join({"z", "o", "v"}, '_');
}