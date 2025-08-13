#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <iterator>


int main()
{
	std::string input;
	std::list <std::string> output;

	while (std::getline(std::cin, input))
	{
		
		if (input == "")
		{
			break;
		}
		output.push_back(input);

	}
	std::list<std::string> ::iterator state = output.begin();
	std::string copy;
	while (std::getline(std::cin, input))
	{
		if ((state != std::prev(output.end())))
		{
			if (input == "Down")
			{
				++state;
			}
		}

		if (state != output.begin())
		{
			if (input == "Up")
			{
				--state;
			}
			if (input == "Ctrl+X")
			{
				copy = *state;
				state = output.erase(state);	
			}
		}
		
		if (state == output.begin())
		{
			if (input == "Ctrl+X")
			{
				copy = *state;
				state = output.erase(state);
			}
		}


		if (input == "Ctrl+V")
		{
			++state;
			output.insert(--state, copy);
		}
		if (input == "")
		{
			break;
		}
	}
	auto end = std :: prev(output.end());
	std::cout << *end;
	if (*end == "")
	{
		output.pop_back();
	}



	for (auto it = output.begin(); it != output.end(); ++it)
	{
		std::cout << *it << '\n';
	}


	 
}