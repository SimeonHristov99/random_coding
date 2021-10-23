#include <iostream>
#include <string>

std::string rot13(const std::string& msg) {
    const int LEN_ALPHABET = 'z' - 'a' + 1;
    std::string result = "";

    for (char c : msg) {
        if (islower(c) != 0) {
            result.push_back('a' + (c - 'a' + 13) % LEN_ALPHABET);
        } else if (isupper(c) != 0) {
            result.push_back('A' + (c - 'A' + 13) % LEN_ALPHABET);
        } else {
            result.push_back(c);
        }
    }
    
    return result;
}

int main() {
    std::cout << rot13("test") << '\n';  // "grfg"
    std::cout << rot13("Test") << '\n';  // "Grfg"
    std::cout << rot13("AbCd") << '\n';  // "NoPq"
    std::cout << rot13("") << '\n';  // ""
    std::cout << rot13("4") << '\n';  // "4"
    std::cout << rot13("Z") << '\n';  // "M"
    std::cout << rot13("t89est") << '\n';  // "g89rfg"
    std::cout << rot13("Test6") << '\n';  // "Grfg6"

    return 0;
}