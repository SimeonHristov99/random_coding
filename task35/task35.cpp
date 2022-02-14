#include <iostream>
#include <string>

std::string createPhoneNumber(const int arr[10])
{
    std::string result;

    result += '(';
    result += arr[0] + '0';
    result += arr[1] + '0';
    result += arr[2] + '0';
    result += ") ";
    result += arr[3] + '0';
    result += arr[4] + '0';
    result += arr[5] + '0';
    result += '-';
    result += arr[6] + '0';
    result += arr[7] + '0';
    result += arr[8] + '0';
    result += arr[9] + '0';

    return result;
}

int main(int argc, char const *argv[])
{
    int a1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::cout << (createPhoneNumber(a1) == "(123) 456-7890") << '\n';

    int a2[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::cout << (createPhoneNumber(a2) == "(111) 111-1111") << '\n';

    int a3[10] = {1, 2, 3, 4, 5, 6, 8, 8, 0, 0};
    std::cout << (createPhoneNumber(a3) == "(123) 456-8800") << '\n';

    int a4[10] = {0, 2, 3, 0, 5, 6, 0, 8, 9, 0};
    std::cout << (createPhoneNumber(a4) == "(023) 056-0890") << '\n';

    int a5[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::cout << (createPhoneNumber(a5) == "(000) 000-0000") << '\n';

    return 0;
}
