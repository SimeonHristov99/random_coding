#include <iostream>

const int INPUT_CAP = 51;

size_t min_take(const int num_stones, char stones[INPUT_CAP])
{
    size_t answer = 0;

    for (int i = 0; i < num_stones - 1; ++i)
    {
        int j = i + 1;
        while (j < num_stones && stones[i] == stones[j])
        {
            ++answer;
            ++j;
        }
        i = j - 1;
    }

    return answer;
}

int main()
{
    int num_stones;
    char stones[INPUT_CAP] = {'\0'};

    std::cin >> num_stones >> stones;

    std::cout << min_take(num_stones, stones) << '\n';

    return 0;
}
