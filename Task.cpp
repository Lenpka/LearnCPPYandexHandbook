#include <iostream>
#include <vector>



#include <iostream>
#include <vector>



std::pair	<size_t, size_t> MatrixArgMax(const std::vector <std::vector <int>>& matrix) //RETURN PAIR, TAKE MATRIX
{
	std::pair<size_t, size_t> para = { 0,0 };
	int max = matrix[0][0];
	if (matrix.size() >= 1 and matrix[0].size() >= 1)
	{
		for (size_t i = 0; i < matrix.size(); i++)
		{
			for (size_t j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] > max)
				{
					para.first = i;
					para.second = j;
					max = matrix[i][j];
				}

			}
		}
	}
	else if (matrix.size() == 0)
	{
		for (size_t j = 1; j < matrix[0].size(); j++)
		{
			if (matrix[0][j] > matrix[0][j - 1])
			{
				para.second = j;
			}
		}
	}
	else if (matrix[0].size() == 0)
	{
		for (size_t i = 1; i < matrix.size(); i++)
		{
			if (matrix[i][0] > matrix[i - 1][0])
			{
				para.first = i;
			}
		}
	}
	return para;
}





int main()
{
	char cont = 'y';
	size_t m, n;
	while (cont == 'y') {
		std::cin >> m >> n;
		std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				std::cin >> matrix[i][j];
			}
		}
		std::string s = "Continue?(y or n) ";
		std::cout << MatrixArgMax(matrix).first << ' ' << MatrixArgMax(matrix).second << '\n'<< s << ' н';
	;
			std::cin  >> cont;
	}
}