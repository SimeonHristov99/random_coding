#include <iostream>

int main()
{
    int n, k, counter = 0, elem;

    std::cin >> n >> k;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];

        if (i == k - 1)
        {
            elem = arr[i];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > 0 && arr[i] >= elem)
        {
            ++counter;
        }
    }

    std::cout << counter;
    delete[] arr;

    return 0;
}