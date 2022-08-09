#include <iostream>
#include <cmath>

size_t getLenN(long long n)
{
    size_t i = 0;
    while (n > 9)
    {
        ++i;
        n /= 10;
    }
    return i + 1;
}

long long maxRot(long long n)
{
    long long max = n;
    size_t lenN = getLenN(n);
    int i = 0;
    long long firstPart, toRotate = 0;

    while (i < lenN)
    {
        long long div = std::pow(10, lenN - i);

        firstPart = n / div;
        toRotate = n % div;

        // rotate left
        toRotate = toRotate % (div / 10) * 10 + toRotate / (div / 10) % 10;

        n = firstPart * div + toRotate;

        if (n > max)
        {
            max = n;
        }
        ++i;
    }

    return max;
}

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha << (maxRot(56789) == 68957) << '\n';
    std::cout << (maxRot(38458215) == 85821534) << '\n';
    std::cout << (maxRot(38458215) == 85821534) << '\n';
    std::cout << (maxRot(195881031) == 988103115) << '\n';
    std::cout << (maxRot(896219342) == 962193428) << '\n';
    std::cout << (maxRot(69418307) == 94183076) << '\n';

    return 0;
}
