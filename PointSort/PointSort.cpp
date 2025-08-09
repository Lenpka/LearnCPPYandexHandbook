// PointSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
double dist(const std::pair<int, int>& coords)
{
    int x = coords.first;
    int y = coords.second;
    double dis = std::sqrt(x * x + y * y);
    return dis;
}

int main()
{
    std::pair<int, int> vvod;
    int n, f, s;
    std::cin >> n;
    std::cin >> f >> s;
    vvod.first = f;
    vvod.second = s;
    std::vector <std::pair<double, int>> distances = { {dist({f,s }) ,0 }
};
    std::vector<std::pair<int, int>> answer = { vvod };
    auto counter = answer.begin();
    for (int i = 1; i < n; i++)
    {
        std::cin >> f >> s;
        vvod.first = f;
        vvod.second = s;
        //if (dist(vvod) < distances[0])
        //{
          //  answer.insert(counter, vvod);
            //counter += 1;
        //}
        //else if (dist(vvod) > distances[0])
        //{
         answer.push_back(vvod);
         distances.push_back({ dist(vvod), i });
         
        //}

        //else if (dist(vvod) == distances[0])
        //{
          //  std::pair<int, int>& ref = answer[i];
            //answer.push_back(vvod);
            //answer[i] = answer[i - 1];
            //answer[i - 1] = ref;
              //  }
    }
    std::sort(distances.begin(), distances.end());

    for (size_t j = 0; j < answer.size(); j++)
    {
        std::cout << answer[distances[j].second].first << ' ' << answer[distances[j].second].second << '\n';
    }
}
