#include <iostream>

int summation(int num)
{
    return num * (num + 1) / 2;
}

int main(int argc, char const *argv[])
{
    std::cout << summation(2) << '\n';
    std::cout << summation(8) << '\n';
    return 0;
}
