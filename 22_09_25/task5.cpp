#include <iostream>

size_t get_borrow_amt(int cost_banana, int budget, int b_to_buy)
{
    size_t total_amt = 0;
    size_t current_cost = cost_banana;

    for (int i = 0; i < b_to_buy; ++i)
    {
        total_amt += current_cost;
        current_cost += cost_banana;
    }

    return (total_amt >= budget ? total_amt - budget : 0);
}

int main()
{
    int cost_banana, budget, b_to_buy;

    std::cin >> cost_banana >> budget >> b_to_buy;

    std::cout << get_borrow_amt(cost_banana, budget, b_to_buy) << '\n';

    return 0;
}
