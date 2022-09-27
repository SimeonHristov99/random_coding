#include <iostream>
#include <set>

const int INPUT_CAP = 101;

const char *should_chat(char input[INPUT_CAP])
{
    std::set<char> distinct;

    for (int i = 0; input[i] != '\0'; ++i)
    {
        distinct.insert(input[i]);
    }

    return (distinct.size() % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!");
}

int main()
{
    char input[INPUT_CAP] = {'\0'};

    std::cin >> input;

    std::cout << should_chat(input) << '\n';

    return 0;
}
