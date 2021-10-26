#include <iostream>

std::string brainLuck(const std::string &code, const std::string &input) {
    int len_input = input.length();
    
    if (input.length() == 0) {
        return "";
    }
    
    std::string result;
    result.resize(len_input, '\0');
    
    std::string::const_iterator it_inp = input.cbegin();
    std::string::const_iterator it_code = code.cbegin();
    std::string::iterator it_res = result.begin();

    while(it_code != code.cend()) {
        if (it_inp == input.end()) {
            return result;
        }

        switch (*it_code) {
            case '>': {
                ++it_inp;
                break;
            }
            case '<': {
                --it_inp;
                break;
            }
            case '+': {
                if (it_res == result.end()) {
                    // std::cout << "nullptr from +";
                    return "";
                }
                // std::cout << "BEFORE +: " << *it_res << '\n';
                *it_res = char((*it_res + 1) % 256);
                // std::cout << "AFTER +: " << *it_res << '\n';
                break;
            }
            case '-': {
                if (it_res == result.end()) {
                    // std::cout << "nullptr from -";
                    return "";
                }
                // std::cout << "BEFORE -: " << *it_res << '\n';
                *it_res = uint(*it_res - 1) % 256;
                // std::cout << "AFTER -: " << *it_res << '\n';
                break;
            }
            case '.': {
                // std::cout << "BEFORE .: " << *it_res << '\n';
                ++it_res;
                // std::cout << "\tRESULT: " << result << '\n' ;
                break;
            }
            case ',': {
                if (it_inp == input.end()) {
                    // std::cout << "nullptr from , BEFORE";
                    return "";
                }
                if (it_res == result.end()) {
                    // std::cout << "nullptr from , BEFORE";
                    return "";
                }
                // std::cout << "BEFORE ," << *it_res << " and the other " << *it_inp << '\n';
                *it_res = *it_inp++;
                // std::cout << "AFTER ," << *it_res << ' ' << *it_inp << '\n';
                if (it_res == result.end()) {
                    // std::cout << "nullptr from ,";
                    return "";
                }
                break;
            }
            case '[': {
                if (*it_code == '0') {
                    while (*it_code != ']') {
                        ++it_code;
                    }
                } else {
                    // std::cout << "going forward from [. code: " << *(it_code + 1) << '\n';
                }

                break;
            }
            case ']': {
                if (int(*it_code) != 0) {
                    while (*it_code != '[') {
                        --it_code;
                    }
                } else {
                    // std::cout << "going forward from ]\n";
                }
                break;
            }
            default: {
                std::cout << "Unsupported instruction!\n";
                return "";
            }
        }

        ++it_code;
    }

    return result;
}

int main() {
    //echo until "255";
    std::string tw = "c";
    tw.append(1,(char) 255);
    std::cout << brainLuck(",.",tw) << '\n'; // "c"

    //echo until "255";
    tw = "c";
    tw.append(1,(char)255);
    std::cout << brainLuck(",+.",tw) << '\n'; // "d"

    //echo until "255";
    tw = "c0";
    tw.append(1,(char) 255);
    std::cout << brainLuck(",.,[.",tw) << '\n'; // "cc"

    //echo until "255";
    tw = "codewars";
    tw.append(1,(char)255);
    std::cout << brainLuck(",+[-.,+]",tw) << '\n'; // "codewars"

    //echo until "0";
    // std::string mw = "codewars";
    // mw.append(1,(char)0);
    // std::cout << brainLuck(",[.[-],]",mw) << '\n'; // "codewars"
       
    //two number multiplier
    // std::string dw;
    // dw.append(1, (char) 7);
    // dw.append(1, (char) 3);
    // std::string result;
    // result.append(1, (char)21);
    // std::cout << brainLuck(",>,<[>[->+>+<<]>>[-<<+>>]<<<-]>>.",dw << '\n'; // 

    return 0;
}