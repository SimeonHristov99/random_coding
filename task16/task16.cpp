#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

typedef std::pair<std::string, int> pair;

std::vector<std::string> permutations(std::string s)
{
    // Out variables
    std::vector<std::string> result;

    // Helper variables
    std::queue<pair> res;
    res.push(pair(s, 0));
    int s_len = s.size();

    // Permute elements.
    while (res.front().second < s_len - 1)
    {
        pair front = res.front();
        res.pop();

        std::string current_str = front.first;
        int permute_idx = front.second;

        int c_len = current_str.length();

        for (int j = permute_idx; j < c_len; ++j)
        {
            std::string current_str_copy = current_str;
            std::swap(current_str_copy[permute_idx], current_str_copy[j]);
            res.push(pair(current_str_copy, permute_idx + 1));
        }
    }

    // Dump the first elements in a vector.
    while (!res.empty())
    {
        result.push_back(res.front().first);
        res.pop();
    }

    // Remove duplicates.
    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());

    return result;
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> result = permutations("ABC");
    for (const std::string& permutation : result)
    {
        std::cout << permutation << ' ';
    }
    std::cout << '\n';

    result = permutations("a");
    for (const auto x : result)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    result = permutations("ab");
    for (const auto x : result)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    result = permutations("aabb");
    for (const auto x : result)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    return 0;
}
