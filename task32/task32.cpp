#include <iostream>
#include <vector>

void reverse_seq(int n, int *result)
{
    for(int i=0; n > 0; ++i)
    {
        result[i] = n--;
    }
}

std::vector<int> reverse_seq(int n)
{
    std::vector<int> result;

    while (n > 0)
    {
        result.push_back(n);
        --n;
    }

    return result;
}

void print_arr(int *arr, int size)
{
    std::cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

void test1()
{
    int n = 1;

    std::cout << (reverse_seq(n) == std::vector<int>{1}) << '\n';

    int *result = new int[n];
    reverse_seq(n, result);
    print_arr(result, n);
    delete[] result;
    result = nullptr;
}

void test2()
{
    int n = 2;

    std::cout << (reverse_seq(2) == std::vector<int>{2, 1}) << '\n';

    int *result = new int[n];
    reverse_seq(n, result);
    print_arr(result, n);
    delete[] result;
    result = nullptr;
}

void test3()
{
    int n = 5;

    std::cout << (reverse_seq(5) == std::vector<int>{5, 4, 3, 2, 1}) << '\n';

    int *result = new int[n];
    reverse_seq(n, result);
    print_arr(result, n);
    delete[] result;
    result = nullptr;
}

void test4()
{
    int n = 10;

    std::cout << (reverse_seq(10) == std::vector<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}) << '\n';

    int *result = new int[n];
    reverse_seq(n, result);
    print_arr(result, n);
    delete[] result;
    result = nullptr;
}

int main(int argc, char const *argv[])
{
    test1();
    test2();
    test3();
    test4();

    return 0;
}
