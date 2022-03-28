#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_VALUE_PARAMETERIZED_DATA
#include "../doctest.h"

#include <iostream>

TEST_CASE("Test case name")
{
    CHECK_EQ(5, 5);
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