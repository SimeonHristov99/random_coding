#include <iostream>
#include <numeric>

long proper_fractions(long n)
{
    if (n < 2)
    {
        return 0;
    }

    long res = 0;

    for (int i = 1; i < n; ++i)
    {
        if(std::gcd(i, n) == 1)
        {
            res += 1;
        }
    }

    return res;
}

void test()
{
    std::cout << std::boolalpha << (proper_fractions(1) == 0) << '\n';
    std::cout << (proper_fractions(2) == 1) << '\n';
    std::cout << (proper_fractions(5) == 4) << '\n';
    std::cout << (proper_fractions(15) == 8) << '\n';
    std::cout << (proper_fractions(25) == 20) << '\n';
}

int main(int argc, char const *argv[])
{
    test();

    return 0;
}
