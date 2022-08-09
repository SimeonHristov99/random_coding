#include <iostream>

bool is_palindrome(const char* str) {
    char normalized[1024] = {'\0'};
    int new_size = 0;
    int middle_idx = -1;

    for (int i = 0; str[i] != '\0'; ++i) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            normalized[new_size++] = str[i] - ('A' - 'a');
        }
        else if ('a' <= str[i] && str[i] <= 'z') {
            normalized[new_size++] = str[i];
        }
    }
    
    middle_idx = new_size / 2;

    for (int i = 0; i < middle_idx; ++i) {
        if(normalized[i] != normalized[new_size - i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::cout << std::boolalpha << (is_palindrome("mana") == false) << '\n';
    std::cout << (is_palindrome("maam") == true) << '\n';
    std::cout << (is_palindrome("manam") == true) << '\n';
    std::cout << (is_palindrome("level") == true) << '\n';
    std::cout << (is_palindrome("algorithm") == false) << '\n';
    std::cout << (is_palindrome("A man, a plan, a canal: Panama.") == true) << '\n';

    return 0;
}