#include <iostream>

std::string brainLuck(const std::string &code, const std::string &input) {
    int len_input = input.length();
    
    if (input.length() == 0) {
        return "";
    }
    
    std::string result;
    result.resize(len_input, '\0');
    
    std::string::const_iterator it_inp = input.cbegin();
    std::string::iterator it_res = result.begin();
    
    for (const char instr : code) {
        
        if (it_inp == input.end()) {
            return result;
        }

        switch (instr) {
            case '>': {
                ++it_inp;
                break;
            }
            case '<': {
                --it_inp;
                break;
            }
            case '+': {
                *it_res = (*it_res + 1) % 256;
                break;
            }
            case '-': {
                *it_res = uint(*it_res - 1) % 256;
                break;
            }
            case '.': {
                ++it_res;
                break;
            }
            case ',': {
                *it_res = *it_inp;
                break;
            }
            case '[': {
                if (int(*it_inp) == 0) {
                    while (*it_inp != ']') {
                        ++it_inp;
                    }
                    ++it_inp;
                } else {
                    ++it_inp;
                }

                break;
            }
            case ']': {
                if (int(*it_inp) != 0) {
                    while (*it_inp != '[') {
                        --it_inp;
                    }
                    ++it_inp;
                } else {
                    ++it_inp;
                }

                break;
            }
            default: {
                std::cout << "Unsupported instruction!\n";
                return "";
            }
        }
    }

    return result;
}

int main() {
    //echo until "255";
    std::string tw = "c";
    tw.append(1,(char)255);
    std::cout << brainLuck(",.",tw) << '\n'; // "c"

    //echo until "255";
    tw = "codewars";
    tw.append(1,(char)255);
    std::cout << brainLuck(",+[-.,+]",tw) << '\n'; // "codewars"

    //echo until "0";
//    std::string mw = "codewars";
//    mw.append(1,(char)0);
//    std::cout << brainLuck(",[.[-],]",mw) << '\n'; // "codewars"
       
    //two number multiplier
//    std::string dw;
//    dw.append(1, (char) 7);
//    dw.append(1, (char) 3);
//    std::string result;
//    result.append(1, (char)21);
//    std::cout << brainLuck(",>,<[>[->+>+<<]>>[-<<+>>]<<<-]>>.",dw << '\n'; // 

    return 0;
}