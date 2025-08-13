	#include <iostream>
	#include <vector>
	#include <string>
	#include <deque>



	std :: pair <size_t, std :: string> getNumOperator( const std::string& vvod)
	{
		std::string strnum, operat;
		for (size_t i = 4; i < vvod.size(); i++)
		{
			if (vvod[i] == ' ')
			{
				strnum = vvod.substr(i, vvod.size() - i);
				operat = vvod.substr(1, i-1);
				return { static_cast<size_t>(std::stoi(strnum)), operat };
			}


		}
	}

	void MakeTrain()
	{
		std::string input;
		int num;
		std::deque <int> train = {};
		std :: pair <int, std:: string> MN;

		while (std :: getline(std::cin, input))
		{

			MN =getNumOperator(input);

			if (input[0] == '+')
			{
				if (MN.second == "left")
				{
					train.push_front(MN.first);
				}
				if (MN.second == "right")
				{
					train.push_back(MN.first);
				}
			}
			else if (input[0] == '-')
			{
				if (MN.first >= train.size())
				{
					train.clear();
					continue;
				}
				if (MN.second == "left")
				{
					train.erase(train.begin(), train.begin() + MN.first);
					/*for (int i = 0; i < MN.first; i++)
					{
						train.pop_front();
					}*/

				}

				if (MN.second == "right")
				{
					train.erase(train.end()-MN.first, train.end());
					//for (int i = 0; i < MN.first; i++)
					//{
					//	train.pop_back();
					//}
				}
			}
		}

		for (auto iter = train.begin(); iter != train.end(); ++iter)
		{
			std::cout << *iter << ' ';
		}
		std::cout << '\n';

	}
int main()
{

	MakeTrain();
}