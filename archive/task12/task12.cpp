#include <iostream>
#include <string>
#include <stack>

std::string sum_strings(const std::string &a, const std::string &b)
{
    int len_a = a.length();
    int len_b = b.length();
    
    std::string result;
    std::stack<char> reversed_num;

    std::string padded_a(a);
    std::string padded_b(b);

    bool add_one = false;

    if (len_a > len_b)
    {
        padded_b = std::string(len_a - len_b, '0') += b;
    }
    else
    {
        padded_a = std::string(len_b - len_a, '0') += a;
    }

    for (int i = padded_a.length() - 1; i >= 0; --i)
    {
        int current_sum = (padded_a[i] - '0') + (padded_b[i] - '0');

        if (add_one)
        {
            if (current_sum > 8)
            {
                current_sum -= 9;
            }
            else
            {
                current_sum += 1;
                add_one = false;
            }
        }
        else if (current_sum > 9)
        {
            current_sum -= 10;
            add_one = true;
        }

        reversed_num.push(current_sum + '0');
    }

    if (add_one)
    {
        reversed_num.push('1');
    }

    while (!reversed_num.empty())
    {
        result += reversed_num.top();
        reversed_num.pop();
    }

    return result;
}

int main(int argc, char const *argv[])
{
    std::cout << sum_strings("10", "35679") << '\n'; // "35689"
    std::cout << sum_strings("99", "99") << '\n';    // "198"
    std::cout << sum_strings("99", "2") << '\n';     // "101"
    std::cout << sum_strings("123", "456") << '\n';  // "579"
    std::cout << sum_strings(
                     "111111111111111111111111111111",
                     "111111111111111111111111111111")
              << '\n'; // "222222222222222222222222222222"

    return 0;
}
