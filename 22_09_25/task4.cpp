#include <iostream>

size_t num_years(int weight_l, int weight_b)
{
    size_t years = 0;

    while (weight_l <= weight_b)
    {
        weight_l *= 3;
        weight_b *= 2;
        ++years;
    }

    return years;
}

int main()
{
    int x, y;

    std::cin >> x >> y;

    std::cout << num_years(x, y) << '\n';

    return 0;
}
