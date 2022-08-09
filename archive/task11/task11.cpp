#include <iostream>
#include <string>

std::string format_duration(int seconds)
{
    if (seconds == 0)
    {
        return "now";
    }

    std::string result;
    const int NUM_UNTS = 5;

    std::string words[NUM_UNTS] = {"years", "days", "hours", "minutes", "seconds"};
    int units[NUM_UNTS] = {31536000, 86400, 3600, 60, 1};

    for (int i = 0; i < NUM_UNTS; i++)
    {
        int current_number = 0;

        while (seconds >= units[i])
        {
            ++current_number;
            seconds -= units[i];
        }

        if (current_number >= 1)
        {
            if (result.length() > 0)
            {
                result += ( seconds == 0 ? " and " : ", ");
            }

            result
                += std::to_string(current_number)
                += std::string(" ")
                += (current_number == 1
                    ? words[i].substr(0, words[i].length() - 1)
                    : words[i]
                );
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    std::cout << format_duration(0) << '\n';    // "now"
    std::cout << format_duration(1) << '\n';    // "1 second"
    std::cout << format_duration(62) << '\n';   // "1 minute and 2 seconds"
    std::cout << format_duration(120) << '\n';  // "2 minutes"
    std::cout << format_duration(3662) << '\n'; // "1 hour, 1 minute and 2 seconds"

    return 0;
}
