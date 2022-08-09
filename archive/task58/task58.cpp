#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include <string>

bool isDigit(const char c)
{
    return '0' <= c && c <= '9';
}

int solve(std::string s)
{
    int result = 0;

    for (const char *c = s.data(); *c; ++c)
    {
        if (isDigit(*c))
        {
            int n = 0;
            while (isDigit(*c))
            {
                n = n * 10 + (*c - '0');
                ++c;
            }
            result += n;
        }
    }

    return result;
}

TEST_CASE("Test case name")
{
    CHECK_EQ(solve("22"), 22);
    CHECK_EQ(solve("22aa22"), 44);
}