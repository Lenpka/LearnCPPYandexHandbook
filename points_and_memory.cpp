#include <iostream>
#include <string>
#include <vector>

int main()
{
	// In C++, unlike Python, a variable just copies information from a link to a new part of memory
	std::string string1 = "Hipotalamus";
	std::string string2 = string1;
	bool compare = (string1 == string2);
	std::cout << "Before Clean:" << compare << std::endl;
	string1.clear();
	bool compare2 = (string1 == string2);
	std::cout << "After Clean:" << compare2 << std::endl;


	// Links

	int variable_x = 9;
	int& link_to_variable_x = variable_x; // IT IS NOT VARIABLE, JUST A LINK TO OBJECT
	++variable_x;
	std::cout << link_to_variable_x << std::endl; //10
	
	//Now link:
	std::cout << "Now link" << std::endl;
	std::string string3 = "Hipotalamus";
	std::string& string4 = string3;
	bool compare3 = (string3 == string4);
	std::cout << "Before Clean:" << compare3 << std::endl;
	string3.clear();
	bool compare4 = (string3 == string4);
	std::cout << "After Clean:" << compare4 << std::endl;

}
