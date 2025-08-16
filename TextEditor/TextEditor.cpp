#include <iostream>
#include <list>
#include <string>
#include <vector>
int main()
{
	std::string inp;
	std::list<std::string> out;

	while (std::getline(std::cin, inp))
	{
		out.push_back(inp);
		if (inp.empty())
		{
			break;
		}

	}
	std::string copy = "";
	std::list <std::string> ::iterator EndShiftState;
	std::list <std::string> ::iterator StartShiftState;
	std::vector <std::string> PasteBoofer;
	std::list<std::string>::iterator state = out.begin();

	bool ShiftState = 0;
	int counter_up = 0;
	int counter_down = 0;
	bool Special = 0;
	std::vector <std::string>ShiftBoofer = {};

	while (std::getline(std::cin, inp))
	{

		//if input not empty
		if (inp.empty())
		{
			break;
		}

	
		
		//UP AND DOWN

		if (out.size() > 0)
		{
			if (inp == "Shift")
			{
				ShiftState = !ShiftState;
				StartShiftState = state;
			}

			if (inp == "Down")
			{

				if (state != std::prev(out.end())and !ShiftState)
				{
					++state;
				}

				else if ((ShiftState and state != std::prev(out.end())and *state != "") and counter_down !=0)
				{
					counter_down += 1;
					++state;
					EndShiftState = state;
					ShiftBoofer.push_back(*state);
					
				}

				else if ( (ShiftState and state == std::prev(out.end())) or (ShiftState and counter_down == 0))
				{
					counter_down += 1;
					EndShiftState = state;
					ShiftBoofer.push_back(*state);
				}
			}
			else if (inp == "Up")
			{
				if (state != out.begin()and !ShiftState)
				{
					--state;
				}
				else if (ShiftState and state != out.begin())
				{
					counter_up += 1;
					ShiftBoofer.push_back(*StartShiftState);
					EndShiftState = state;
					--state;

				}
			}

			//CTRL+X


			else if (inp == "Ctrl+X")
			{
				if ((!ShiftState) and (!state->empty()) and (state != std::prev(out.end())))
				{
					copy = *state;
					state = out.erase(state);
					ShiftBoofer = {};
				}
				else if ((!ShiftState) and (!state->empty()) and (state != std::prev(out.end())))
				{
					copy = *state;
					*state = "";
					ShiftBoofer = {};
				}
				if ((counter_down == counter_up) and counter_down != 0)
				{
					Special = 1;
				}


				if ((ShiftState) and (ShiftBoofer.size() > 0) and (!Special))
				{
					if ((std::distance(StartShiftState, EndShiftState) >= 0) and (std::next(EndShiftState) != out.end()))
					{
						out.erase(StartShiftState, std::next(EndShiftState));
					}
					else if ((std::distance(StartShiftState, EndShiftState) > 0) and (std::next(EndShiftState) == out.end()))
					{
						out.erase(StartShiftState, EndShiftState);
					}
					else if ((std::distance(StartShiftState, EndShiftState)) < 0)
					{
						out.erase(EndShiftState, StartShiftState);
					}
					ShiftState = 0;
					PasteBoofer = ShiftBoofer;
					ShiftBoofer = {};
				}
				else if ((ShiftState) and (ShiftBoofer.size() > 0) and (Special))
				{
					if ((std::distance(StartShiftState, EndShiftState) >= 0) and (std::next(EndShiftState) != out.end()))
					{
						out.erase(StartShiftState, std::next(EndShiftState));
					}
					else if ((std::distance(StartShiftState, EndShiftState) > 0) and (std::next(EndShiftState) == out.end()))
					{
						out.erase(StartShiftState, EndShiftState);
					}
					else if ((std::distance(StartShiftState, EndShiftState)) < 0)
					{
						out.erase(EndShiftState, StartShiftState);
					}
					ShiftState = 0;
					PasteBoofer.push_back(copy);
				}
				StartShiftState = state;
				counter_down = 0;
				counter_up = 0;

			}
			//CTRL+V
			else if ((inp == "Ctrl+V"))
			{
				if (!ShiftState and !copy.empty())
				{
					if (state != out.begin())
					{
						out.insert(state, copy);
					}
					else if (state == out.begin() and state->empty())
					{
						*state = copy;
					}
					else if (state == out.begin() and !state->empty())
					{
						out.insert(state, copy);
					}

				}

				else if (ShiftState and (ShiftBoofer.size() > 0))
				{
					//ВЫРЕЗАТЬ И ВСТАВИТЬ НА ЭТИ ПОЗИЦИИ
					out.insert(StartShiftState, PasteBoofer.begin(), PasteBoofer.end());
					if (std::distance(StartShiftState, EndShiftState) > 0)
					{
						out.erase(StartShiftState, std::next(EndShiftState));
					}

					else if ((std::distance(StartShiftState, EndShiftState)) < 0)
					{
						out.erase(EndShiftState, StartShiftState);
					}
					ShiftState = 0;
					PasteBoofer = ShiftBoofer;
					ShiftBoofer = {};
				}
			}
		}
	}
	if (out.size() > 0)
	{
		for (auto iter = out.begin(); iter != std::prev(out.end()); ++iter)
		{
			std::cout << *iter << '\n';

		}
	}
	else
	{
		std::cout << '\n';
	}

}