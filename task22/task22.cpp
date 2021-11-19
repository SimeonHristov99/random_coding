#include <iostream>

int *find_smallest(const int *input, const int size)
{
    int *result = new int[size];

    for (int i = 0; i < size; i++)
    {
        bool found = false;

        for (int j = i - 1; j >= 0; --j)
        {
            if (input[j] < input[i])
            {
                result[i] = input[j];
                found = true;
                break;
            }
        }

        if (!found)
        {
            result[i] = -1;
        }
    }

    return result;
}

void test1()
{
    int size = 7;
    int input[] = {2, 5, 3, 7, 8, 1, 9};
    int *result = find_smallest(input, size);

    for (int i = 0; i < size; i++)
    {
        std::cout << result[i] << ' ';
    }
    std::cout << '\n';

    delete[] result;
    result = nullptr;
}

void test2()
{
    int size = 6;
    int input[] = {5, 7, 4, 9, 8, 10};
    int *result = find_smallest(input, size);

    for (int i = 0; i < size; i++)
    {
        std::cout << result[i] << ' ';
    }
    std::cout << '\n';

    delete[] result;
    result = nullptr;
}

void test3()
{
    int size = 8;
    int input[] = {1, 5, 2, 2, 2, 5, 5, 4};
    int *result = find_smallest(input, size);

    for (int i = 0; i < size; i++)
    {
        std::cout << result[i] << ' ';
    }
    std::cout << '\n';

    delete[] result;
    result = nullptr;
}

int main(int argc, char const *argv[])
{
    test1();
    test2();
    test3();

    return 0;
}
