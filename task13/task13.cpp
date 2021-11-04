#include <iostream>
#include <vector>
#include <cmath>

class CaesarCipher
{
public:
    static std::vector<std::string> movingShift(const std::string &s, int shift);
    static std::string demovingShift(std::vector<std::string> &s, int shift);
};

std::vector<std::string> CaesarCipher::movingShift(const std::string &s, int shift)
{
    std::vector<std::string> result;
    int len_s = s.length();
    std::string s_copy = s.substr(0, len_s);
    int splits = ceil(len_s / 5.0);

    for (int i = 0; i < len_s; i++)
    {
        if (isalpha(s_copy[i]))
        {
            char to_sub = (islower(s_copy[i]) ? 'a' : 'A');
            s_copy[i] = to_sub + ((s_copy[i] - to_sub) + shift) % 26;
        }
        ++shift;
    }

    for (int i = 0; i < len_s; i += splits)
    {
        result.push_back(s_copy.substr(i, splits));
    }

    int len_res = result.size();
    while (len_res < 5)
    {
        result.push_back("");
        ++len_res;
    }

    return result;
}

std::string CaesarCipher::demovingShift(std::vector<std::string> &s, int shift)
{
    std::string result;

    for (const std::string curr_s : s)
    {
        for (const char c : curr_s)
        {
            if (isalpha(c))
            {
                char to_sub = (islower(c) ? 'a' : 'A');
                char last_letter = (islower(c) ? 'z' : 'Z');
                int diff = (((c - to_sub) - shift) % 26);
                if (diff < 0)
                {
                    result += last_letter + diff + 1;
                }
                else
                {
                    result += to_sub + diff;
                }
            }
            else
            {
                result += c;
            }

            ++shift;
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    std::string u = "I should have known that you would have a perfect answer for me!!!";

    std::vector<std::string> result = CaesarCipher::movingShift(u, 1);

    std::cout << "[ ";
    for (const std::string &s : result)
    {
        std::cout << s << ", ";
    }
    std::cout << " ]\n";

    std::cout << "\nAfter demoving: " << CaesarCipher::demovingShift(result, 1) << '\n';

    return 0;
}
