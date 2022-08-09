#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int n;

    cin >> n;

    std::cout << (n % 2 == 0 && n > 2 ? "YES" : "NO");

    return 0;
}
