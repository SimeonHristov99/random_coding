#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_VALUE_PARAMETERIZED_DATA
#include "../doctest.h"

#include <iostream>
#include <vector>

template <class T>
std::vector<T> intersect(const std::vector<T> &v1, const std::vector<T> &v2)
{
    std::vector<T> res;

    for (const T &x : v1)
    {
        bool seen = false;
        for (const T &z : res)
        {
            if (z == x)
            {
                seen = true;
                break;
            }
        }

        if (seen)
        {
            continue;
        }

        for (const T &y : v2)
        {
            if (x == y)
            {
                res.push_back(x);
                break;
            }
        }
    }

    return res;
}

TEST_CASE("Test for strings")
{
    std::vector<std::string> v1{"green", "orange", "blue", "red"};
    std::vector<std::string> v2{"black", "green", "red", "purple"};
    std::vector<std::string> expected{"green", "red"};

    CHECK_EQ(intersect(v1, v2), expected);
}

TEST_CASE("Test 1 for numbers")
{
    std::vector<int> v1{1, 2, 2, 1};
    std::vector<int> v2{2, 2};
    std::vector<int> expected{2};

    CHECK_EQ(intersect(v1, v2), expected);
}

TEST_CASE("Test 2 for numbers")
{
    std::vector<int> v1{4, 9, 5};
    std::vector<int> v2{9, 4, 9, 8, 4};
    std::vector<int> expected{4, 9};

    CHECK_EQ(intersect(v1, v2), expected);
}

int main(int argc, char **argv)
{
    doctest::Context context;

    context.setOption("abort-after", 5);   // stop test execution after 5 failed assertions
    context.setOption("order-by", "name"); // sort the test cases by their name

    context.applyCommandLine(argc, argv);

    int res = context.run(); // run the tests

    if (context.shouldExit()) // query flags (and --exit) rely on the user doing this
    {
        return res; // propagate the result of the tests
    }

    int client_stuff_return_code = 0;

    return res + client_stuff_return_code; // the result from doctest is propagated here as well
}