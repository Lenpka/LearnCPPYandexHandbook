#include <iostream>
#include <string>
#include <deque>
#include <utility>
#include <vector>

int main()
{
	size_t N, M;
	std::string surname;
	std::deque<std::pair<size_t, std::string>> stack;
	std::string fam;
	std::string position;
	//Students
	std::cin >> N;
	for (size_t i = 1; i <= N; i++)
	{
		std::cin >> fam >> position;
		std::pair <size_t, std::string> surname = { i,fam };
		if (position == "top")
		{
			stack.push_front(surname);
		}
		else if (position == "bottom")
		{
			stack.push_back(surname);
		}
	}

	//std::sort(stack.begin(), stack.end());

	std::cin >> M;
	size_t num;
	std:: vector <std::string> ans;
	if (M == 0)
	{
		std::cout << "";
	}
	if (M > 0)
	{
	for (size_t j = 0; j < M;j++)
	{
		std::cin >> num;
		ans.push_back(stack[num-1].second);
	}
	for (size_t k = 0; k < ans.size() - 1; k++)
	{
		std::cout << ans[k] << '\n';
	}
	std::cout << ans[ans.size()- static_cast < size_t>(1)
	];
}