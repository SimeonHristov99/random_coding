#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_VALUE_PARAMETERIZED_DATA
#include "../doctest.h"

bool zero_fuel(uint32_t distance_to_pump, uint32_t mpg, uint32_t fuel_left)
{
    return distance_to_pump <= mpg * fuel_left;
}

TEST_CASE("Test case name")
{
    CHECK(zero_fuel(50, 25, 2));
    CHECK_FALSE(zero_fuel(100, 50, 1));
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