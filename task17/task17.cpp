#include <iostream>
#include <set>

// brute force
bool nums_add_up_bf(int k, int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[i] + arr[j] == k)
            {
                return true;
            }
        }
    }

    return false;
}

// in linear time and space
bool nums_add_up_lt(int k, int *arr, int size)
{
    std::set<int> s;

    for (int i = 0; i < size; ++i)
    {
        std::set<int>::iterator it = s.find(arr[i]);
        
        if (it != s.end())
        {
            return true;
        }

        s.insert(k - arr[i]);
    }

    return false;
}

int main(int argc, char const *argv[])
{
    int arr[4] = {10, 15, 3, 7};
    std::cout << std::boolalpha << nums_add_up_bf(17, arr, 4) << '\n'; //true
    std::cout << nums_add_up_lt(17, arr, 4) << '\n'; //true

    return 0;
}
