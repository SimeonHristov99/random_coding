#include <iostream>
#include <string>

std::string switch_it_up(int number)
{
    std::string n_to_s[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    return n_to_s[number];
}

int main(int argc, char const *argv[])
{
    std::cout << switch_it_up(1) << '\n'; // One
    std::cout << switch_it_up(9) << '\n'; // Nine
    return 0;
}
