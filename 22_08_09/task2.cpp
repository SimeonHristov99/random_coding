// TASK: https://codeforces.com/problemset/problem/71/A

#include <iostream>
#include <string>

int main()
{
    int n;
    std::string word;

    std::cin >> n;

    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> word;
        size_t len_word = word.size();

        if (len_word > 10)
        {
            std::cout << word[0] << len_word - 2 << word[len_word - 1] << '\n';
        }
        else
        {
            std::cout << word << '\n';
        }
    }

    return 0;
}
