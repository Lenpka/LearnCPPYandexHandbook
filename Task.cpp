// Task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

int max(std:: vector <int> range)
{
	int maximum = range[0];
	for (size_t j = 1; j < range.size(); j++)
	{
		if (range[j] > range[j - 1])
		{
			maximum = range[j];
		}
	}
	return maximum;
}

int FindMaxInRange(std::vector<int> work)
{
	int StartMaxIndex = 0;
	//int* ref = &StartMaxIndex;
	for (size_t y = 1; y < work.size(); y++)
	{
		if (work[y] > work[y - 1]) 
		{
			StartMaxIndex = static_cast<int>(y);

	}
	}
	return StartMaxIndex; // Номер столбца (+1)
}

//struct ToSearch
//{
//	int value;
//	int row;
//	int column;
//};


std::pair	<size_t, size_t> MatrixArgMax(const std::vector <std::vector <int>>& matrix) //RETURN PAIR, TAKE MATRIX
{
	//std::vector<ToSearch> MaximumsInRowIndex(matrix.size());
	std::pair <int, int> para = { max(matrix[0]), 0};

	if (static_cast<int>(matrix.size()) > 1)
	{
		for (size_t i = 1; i < matrix.size(); i++)
		{
			//0 1 10 3
			//40 30 2 12
			//45 567 76 -> {10,40,567} - Максимум не нужен
			//
		//	MaximumsInRowIndex.push_back({max(matrix[i]),static_cast<int>(i), FindMaxInRange(matrix[i])});
			if (max(matrix[i]) > max(matrix[i - 1]))
			{
				para.first = static_cast<int>(i);
				para.second = FindMaxInRange(matrix[i]);
			}

		}
		return para;
	}
	else
	{
		para = { 0,FindMaxInRange(matrix[0]) };
		return para;
	}
	
	
}

//std::string func(int a, int b)
//{
//	if (a < b) {
//		std::string name = "ress";
//		return name;
//	}
//	else {
//		std::string ans = "Tress";
//			return ans;
//	}
//}
int main()
{
//	std :: cout << func(2, 1);
	size_t m, n; // размеры матрицы 3 на 4
	std::cin >> m >> n;
	std::vector<std::vector<int>> matrix (m,std::vector <int>(n) );
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cin >> matrix[i][j];
	}
	}

	std::pair<int, int>  ans =  MatrixArgMax(matrix);
	std::cout << ans.first << ' ' << ans.second; // 3 4

}