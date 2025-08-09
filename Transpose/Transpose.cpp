// Transpose.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>


std::vector<std::vector <int>> Transpose(const std::vector<std::vector <int>>& matrix)
{
    std::vector <std::vector<int>> matrixTranspose (matrix.size(), std::vector<int> (matrix[0].size()));
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            matrixTranspose[i][j] = matrix[j][i];
        }
    }
    return matrixTranspose;
}



int main()
{
     size_t m, n;
     std::cin >> m >> n;
    std::vector <std::vector<int>> matrix(m, std::vector <int>(n)), Tmatrix (n, std :: vector<int> (m));


    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            std::cin >> matrix[i][j];
            

        }
    }
    Tmatrix = Transpose(matrix);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            std::cout <<  Tmatrix[i][j];

        }
    }

}

