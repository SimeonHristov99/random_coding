#include <iostream>

unsigned num_steps(int goal)
{
    unsigned steps = 0;

    for (unsigned current = 5; goal > 0 && current > 0; --current)
    {
        while (goal > 0 && goal >= current)
        {
            goal -= current;
            ++steps;
        }
    }

    return steps;
}

int main()
{
    int goal;

    std::cin >> goal;

    std::cout << num_steps(goal) << '\n';

    return 0;
}
