#include <iostream>
#include <string>
#include <vector>

std::string permute_one_iter(char c, const std::string &s)
{
    std::vector<std::string> res = {s};
    int s_len = s.size();
    int i = 0;

    for (std::vector<std::string>::const_iterator it = res.begin(); i < s_len && it != res.end(); ++it)
    {
        std::string current_str = res[0];
        int c_len = current_str.length();

        res.erase(res.begin());

        for (int j = i; j < c_len; ++j)
        {
            std::string current_str_copy = current_str;
            std::swap(current_str_copy[i], current_str_copy[j]);
            res.push_back(current_str_copy);
        }

        ++i;
    }

    return "";
}

std::vector<std::string> permutations(std::string s)
{
    std::vector<std::string> result;

    for (const char c : s)
    {
    }

    return result;
}

int main(int argc, char const *argv[])
{
    permute_one_iter('A', "ABC");
    // std::vector<std::string> result = permutations("a");

    // for (const auto x : result)
    // {
    //     std::cout << x << ' ';
    // }

    // result = permutations("ab");

    // for (const auto x : result)
    // {
    //     std::cout << x << ' ';
    // }

    // result = permutations("aabb");

    // for (const auto x : result)
    // {
    //     std::cout << x << ' ';
    // }

    return 0;
}
