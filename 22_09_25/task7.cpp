#include <iostream>

const int INPUT_CAP = 101;

std::pair<int, int> count_low_cap(char input[INPUT_CAP])
{
    std::pair<int, int> res = {0, 0};

    for (int i = 0; input[i] != '\0'; ++i)
    {
        if (input[i] <= 'Z')
        {
            ++res.first;
        }
        else
        {
            ++res.second;
        }
    }

    return res;
}

void convert(char input[INPUT_CAP], char output[INPUT_CAP])
{
    std::pair<int, int> counts = count_low_cap(input);
    bool capitalize = (counts.first > counts.second);

    for (int i = 0; input[i] != '\0'; ++i)
    {
        output[i] = (capitalize ? std::toupper(input[i]) : std::tolower(input[i]));
    }
}

int main()
{
    char input[INPUT_CAP] = {'\0'};
    char output[INPUT_CAP] = {'\0'};

    std::cin >> input;

    convert(input, output);

    std::cout << output << '\n';

    return 0;
}
