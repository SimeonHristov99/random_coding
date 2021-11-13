#include <iostream>

int max_profit(int *prices, int size)
{
    int idx_min = 0;
    int highest_price = -1;

    for (int i = 0; i < size - 1; ++i)
    {
        if (prices[i] > prices[i + 1])
        {
            int current_price = prices[i] - prices[idx_min];
            highest_price = (current_price > highest_price ? current_price : highest_price);
            idx_min = i + 1;
        }
    }
    
    if (prices[size - 1] > prices[size - 2])
    {
        int current_price = prices[size - 1] - prices[idx_min];
        highest_price = (current_price > highest_price ? current_price : highest_price);
    }

    return highest_price;
}

int main(int argc, char const *argv[])
{
    int prices1[6] = {9, 11, 8, 5, 7, 10};
    std::cout << max_profit(prices1, 6) << '\n'; // 5

    int prices2[6] = {9, 11, 8, 10, 7, 5};
    std::cout << max_profit(prices2, 6) << '\n'; // 2

    return 0;
}
