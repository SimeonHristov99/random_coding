#include <iostream>

bool all_caps(const char *string)
{
    for (const char *c = string; *c; ++c)
    {
        if (!('A' <= *c && *c <= 'Z'))
        {
            return false;
        }
    }

    return true;
}

bool all_lower(const char *string)
{
    for (const char *c = string; *c; ++c)
    {
        if (!('a' <= *c && *c <= 'z'))
        {
            return false;
        }
    }

    return true;
}

bool only_first(const char *string)
{
    return 'A' <= string[0] && string[0] <= 'Z' && all_lower(++string);
}

bool correct_capitalization(const char *string)
{
    return string != nullptr
            && (all_caps(string)
                || only_first(string)
                || all_lower(string));
}

int main(int argc, char const *argv[])
{
    std::cout << std::boolalpha << correct_capitalization("USA") << '\n'; // true
    std::cout << correct_capitalization("Calvin") << '\n';                // true
    std::cout << correct_capitalization("compUter") << '\n';              // false
    std::cout << correct_capitalization("coding") << '\n';                // true
    std::cout << correct_capitalization("") << '\n';                      // true
    std::cout << correct_capitalization(nullptr) << '\n';                 // false

    return 0;
}
