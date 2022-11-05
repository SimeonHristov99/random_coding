#include <iostream>

const size_t CAP = 2000;

unsigned get_min_idx(int nums[CAP], const size_t len)
{
    int min = nums[0];

    for (size_t i = 1; i < len; ++i)
    {
        if (nums[i] < min)
        {
            min = nums[i];
        }
    }

    return min;
}

unsigned get_max_idx(int nums[CAP], const size_t len)
{
    int max = nums[0];

    for (size_t i = 1; i < len; ++i)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }

    return max;
}

unsigned min_rot(int nums[CAP], const size_t len)
{
    unsigned min = get_min_idx(nums, len);
    unsigned max = get_max_idx(nums, len);

    // if (min_idx == 0 && max_idx == len - 1)
    // {
    //     return 0;
    // }

    // if (min_idx == 0)
    // {
    //     return len - max_idx + 1;
    // }

    // if (max_idx == len - 1)
    // {
    //     return min_idx + 1;
    // }

    return max - min;
}

int main()
{
    unsigned num_tests = 0;
    size_t len = 0;
    int nums[CAP];
    int res[CAP];

    std::cin >> num_tests;

    for (size_t i = 0; i < num_tests; ++i)
    {
        std::cin >> len;

        for (size_t i = 0; i < len; ++i)
        {
            std::cin >> nums[i];
        }

        res[i] = min_rot(nums, len);
    }

    for (size_t i = 0; i < num_tests; ++i)
    {
        std::cout << res[i] << '\n';
    }

    return 0;
}
