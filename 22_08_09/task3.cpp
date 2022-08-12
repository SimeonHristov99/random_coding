// TASK: https://codeforces.com/problemset/problem/231/A

#include <iostream>
#include <string>

int main()
{
    int n, x1, x2, x3, counter = 0;
    std::cin >> n;

    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> x1 >> x2 >> x3;
        if (x1 + x2 + x3 > 1)
        {
            ++counter;
        }
    }

    std::cout << counter;

    return 0;
}
