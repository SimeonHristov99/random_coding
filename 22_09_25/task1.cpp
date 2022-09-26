#include <iostream>

const int INPUT_CAP = 1001;

int main()
{
    char input[INPUT_CAP] = {'\0'};

    std::cin >> input;

    input[0] = toupper(input[0]);

    std::cout << input << '\n';

    return 0;
}
