#include <iostream>

int expand_palind(const std::string &s, const size_t i, const size_t len_s, bool odd)
{
    int len = 1;

    int left = i - 1;
    int right = i + 1;

    if (!odd)
    {
        if (i - 1 >= 0 && s[i - 1] == s[i])
        {
            left = i - 2;
            ++len;
        }
        else
        {
            return 1;
        }
    }

    while (left >= 0 && right < len_s && s[left] == s[right])
    {
        len += 2;
        --left;
        ++right;
    }

    return len;
}

int longest_palindrome(const std::string &s)
{
    size_t len_s = s.length();
    int max_len = 0;

    for (size_t i = 0; i < len_s; ++i)
    {
        int current_len_ev = expand_palind(s, i, len_s, true);
        int current_len_odd = expand_palind(s, i, len_s, false);
        int current_len = std::max(current_len_ev, current_len_odd);

        if (current_len > max_len)
        {
            max_len = current_len;
        }
    }

    return max_len;
}

int main()
{
    std::cout << longest_palindrome("") << '\n';                                                // 0
    std::cout << longest_palindrome("xyx") << '\n';                                             // 3
    std::cout << longest_palindrome("xyyx") << '\n';                                            // 4
    std::cout << longest_palindrome("racecars") << '\n';                                        // 7
    std::cout << longest_palindrome("I like racecars that go fast") << '\n';                    // 7
    std::cout << longest_palindrome("a") << '\n';                                               // 1
    std::cout << longest_palindrome("aa") << '\n';                                              // 2
    std::cout << longest_palindrome("baa") << '\n';                                             // 2
    std::cout << longest_palindrome("aab") << '\n';                                             // 2
    std::cout << longest_palindrome("zyabyz") << '\n';                                          // 1
    std::cout << longest_palindrome("baabcd") << '\n';                                          // 4
    std::cout << longest_palindrome("baablkj12345432133d") << '\n';                             // 9
    std::cout << longest_palindrome("lolollolollolollolol") << '\n';                            // 20
    std::cout << longest_palindrome("abcdefghijklmnopqrstuvwxyz lolollolollolollolol") << '\n'; // 20

    return 0;
}