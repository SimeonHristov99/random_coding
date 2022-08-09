#include <iostream>

int getRealFloor(int f)
{
    return f - (0 < f && f < 13) - ((f > 12) * 2);
}

int main(int argc, char const *argv[])
{
    std::cout << getRealFloor(1) << '\n';
    std::cout << getRealFloor(0) << '\n';
    std::cout << getRealFloor(5) << '\n';
    std::cout << getRealFloor(15) << '\n';
    std::cout << getRealFloor(-3) << '\n';

    return 0;
}
