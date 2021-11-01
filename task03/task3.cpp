#include <iostream>

bool will_it_return(const char* path) {
    int pos_x = 0;
    int pos_y = 0;

    for (const char* c = path; *c; ++c) {
        switch (*c) {
            case 'L': {
                pos_x += 1;
                break;
            }
            case 'R': {
                pos_x -= 1;
                break;
            }
            case 'U': {
                pos_y += 2;
                break;
            }
            case 'D': {
                pos_y -= 2;
                break;
            }
            default: {
                std::cout << "ERROR: Invalid direction!\n";
                return false;
            }
        }
    }

    return pos_x == 0 && pos_y == 0;
}

int main() {
    std::cout << std::boolalpha << will_it_return("LR") << '\n'; // true
    std::cout << will_it_return("URURD") << '\n'; // false
    std::cout << will_it_return("RUULLDRD") << '\n'; // true

    return 0;
}