#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_VALUE_PARAMETERIZED_DATA
#include "../doctest.h"

#include <iostream>

#include <vector>
#include <string.h>

void parse(const std::string &str, std::vector<int> &nums, std::vector<char> &ops)
{
    int str_len = str.length();

    for (int i = 0; i < str_len; ++i)
    {
        std::string num_str;

        while (std::isdigit(str[i]))
        {
            num_str += str[i];
            ++i;
        }

        if (!num_str.empty())
        {
            nums.push_back(std::atoi(num_str.c_str()));
        }
        else
        {
            while (!std::isdigit(str[i]))
            {
                num_str += str[i];
                ++i;
            }
            ops.push_back(num_str == "plus" ? '+' : '-');
        }
        --i;
    }
}

std::string calculate(std::string str)
{
    std::vector<int> nums;
    std::vector<char> ops;

    parse(str, nums, ops);

    int ops_len = ops.size();
    int result = nums[0];

    for (int i = 0; i < ops_len; ++i)
    {
        result = result + (ops[i] == '+' ? 1 : (-1)) * nums[i + 1];
    }

    return std::to_string(result);
}

TEST_CASE("Test 1")
{
    CHECK_EQ(calculate("1plus2plus3plus4"), "10");
}

TEST_CASE("Test 2")
{
    CHECK_EQ(calculate("1minus2minus3minus4"), "-8");
}
TEST_CASE("Test 3")
{
    CHECK_EQ(calculate("1plus2plus3minus4"), "2");
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