#include <iostream>

int main()
{
    int n;
    int k;

    int passed = 0;
    int passed_points = 0;
    int current_score = -1;

    std::cin >> n >> k;

    while (n)
    {
        std::cin >> current_score;

        if (k == 1)
        {
            passed_points = current_score;
        }

        if (current_score <= 0 || k <= 0 && current_score < passed_points)
        {
            break;
        }

        ++passed;
        --k;
        --n;
    }

    std::cout << passed << '\n';

    return 0;
}
