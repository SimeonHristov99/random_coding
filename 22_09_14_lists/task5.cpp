#include <iostream>

const int SIZE = 101;

int ord_len(char arr1[SIZE], char arr2[SIZE])
{
    char *a1 = arr1;
    char *a2 = arr2;

    while (*a1 && *a2 && std::tolower(*a1) == std::tolower(*a2))
    {
        ++a1;
        ++a2;
    }

    if (!*a1 && !*a2)
    {
        return 0;
    }

    return (std::tolower(*a1) < std::tolower(*a2) ? -1 : 1);
}

int main()
{
    char arr1[SIZE] = {'\0'};
    char arr2[SIZE] = {'\0'};

    std::cin >> arr1 >> arr2;

    std::cout << ord_len(arr1, arr2) << '\n';

    return 0;
}