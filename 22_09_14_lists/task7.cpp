#include <iostream>

const int INPUT_SIZE = 101;

void sort(char input[INPUT_SIZE], char output[INPUT_SIZE])
{
    size_t idx_output = 0;
    unsigned digs[3] = {0, 0, 0};

    for (int i = 0; input[i] != '\0'; ++i)
    {
        if (input[i] > '0' && input[i] < '4')
        {
            ++digs[input[i] - '0' - 1];
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < digs[i]; ++j)
        {
            output[idx_output] = '0' + (i + 1);
            ++idx_output;
            output[idx_output] = '+';
            ++idx_output;
        }
    }

    output[idx_output - 1] = '\0';
}

int main()
{
    char input[INPUT_SIZE] = {'\0'};
    char output[INPUT_SIZE] = {'\0'};

    std::cin >> input;

    sort(input, output);
    std::cout << output << '\n';

    return 0;
}
