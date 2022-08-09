#include <iostream>
#include <string>
#include <map>

class RomanHelper
{
private:
    const static int ROWS = 13;
    const static int COLS = 2;

    std::string table[ROWS][COLS] = {
        {"I", "1"},
        {"IV", "4"},
        {"V", "5"},
        {"IX", "9"},
        {"X", "10"},
        {"XL", "40"},
        {"L", "50"},
        {"XC", "90"},
        {"C", "100"},
        {"CD", "400"},
        {"D", "500"},
        {"CM", "900"},
        {"M", "1000"},
    };

    std::map<std::string, int> m{
        {"I", 1},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000},
    };

public:
    std::string to_roman(unsigned int n)
    {
        std::string result;

        while (n > 0) // Continue until n == 0.
        {
            // Find the largest number, that is less than or equal to n.
            int i = ROWS - 1;
            int current_number = -1;
            for (; i >= 0; --i)
            {
                current_number = atoi(table[i][1].c_str());

                if (current_number <= n)
                {
                    break;
                }
            }

            // Add the roman literal to result.
            result += table[i][0];

            // Subtract d from n.
            n -= current_number;
        }

        return result;
    }

    int from_roman(std::string rn)
    {
        int input_len = rn.length();
        int result = 0;

        int i = 0;

        while (i < input_len)
        {
            auto search = m.find(rn.substr(i, 2));
            if (search == m.end())
            {
                search = m.find(rn.substr(i, 1));
                --i;
            }

            result += search->second;

            i += 2;
        }

        return result;
    }

} RomanNumerals;

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha << (RomanNumerals.to_roman(1000) == "M") << '\n';
    std::cout << (RomanNumerals.to_roman(4) == "IV") << '\n';
    std::cout << (RomanNumerals.to_roman(1) == "I") << '\n';
    std::cout << (RomanNumerals.to_roman(9) == "IX") << '\n';
    std::cout << (RomanNumerals.to_roman(1990) == "MCMXC") << '\n';
    std::cout << (RomanNumerals.to_roman(2008) == "MMVIII") << '\n';
    std::cout << (RomanNumerals.to_roman(3999) == "MMMCMXCIX") << '\n';

    std::cout << (RomanNumerals.from_roman("XXI") == 21) << '\n';
    std::cout << (RomanNumerals.from_roman("I") == 1) << '\n';
    std::cout << (RomanNumerals.from_roman("IX") == 9) << '\n';
    std::cout << (RomanNumerals.from_roman("IV") == 4) << '\n';
    std::cout << (RomanNumerals.from_roman("MMVIII") == 2008) << '\n';
    std::cout << (RomanNumerals.from_roman("MDCLXVI") == 1666) << '\n';

    return 0;
}
