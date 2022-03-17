#include <iostream>

void pad(std::string &s, int to_add)
{
    while (to_add--)
    {
        s.insert(0, 1, '0');
    }
}

std::string add_bin(const std::string &s1, const std::string &s2)
{
    int s1_len = s1.length();
    int s2_len = s2.length();

    int max_len = std::max(s1.length(), s2.length());
    std::string result, s1_cp(s1), s2_cp(s2);
    int carry = 0;

    if (s1_len < max_len)
    {
        pad(s1_cp, s2_len - s1_len);
    }
    else if (s2_len < max_len)
    {
        pad(s2_cp, s1_len - s2_len);
    }

    for (int i = max_len - 1; i >= 0; --i)
    {
        int z = (s1_cp[i] - '0') + (s2_cp[i] - '0' + carry);
        result.insert(0, 1, (z % 2) + '0');
        carry = z / 2;
    }

    if (carry > 0)
    {
        result.insert(0, 1, '1');
    }

    return result;
}

int main(int argc, char const *argv[])
{
    std::cout << add_bin("100", "1") << '\n';      // "101"
    std::cout << add_bin("11", "1") << '\n';       // "100"
    std::cout << add_bin("1", "0") << '\n';        // "1"
    std::cout << add_bin("111", "10") << '\n';     // '1001'
    std::cout << add_bin("1101", "101") << '\n';   // '10010'
    std::cout << add_bin("1101", "10111") << '\n'; // '100100'

    return 0;
}
