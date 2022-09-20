#include <iostream>

const int ROWS = 5;
const int COLS = 5;

std::pair<int, int> find_one(int mat[ROWS][COLS])
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            if (mat[i][j] == 1)
            {
                return {i + 1, j + 1};
            }
        }
    }

    return {-1, -1};
}

int min_num_steps(int mat[ROWS][COLS])
{
    std::pair<int, int> start = find_one(mat);
    std::pair<int, int> goal = {3,3};

    // manhattan distance
    return std::abs(start.first - goal.first) + std::abs(start.second - goal.second);
}

int main()
{
    int mat[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            std::cin >> mat[i][j];
        }
    }

    std::cout << min_num_steps(mat) << '\n';

    return 0;
}
