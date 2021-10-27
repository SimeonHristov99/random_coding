#include <iostream>
#include <stack>

std::string brainLuck(const std::string &code, const std::string &input) {
    int len_input = input.length();
    
    if (input.length() == 0) {
        return "";
    }
    
    std::string result_string;
    // result_string.resize(len_input, '\0');

    std::stack<char> result_stack;
    std::string::const_iterator it_input = input.cbegin();
    
    std::stack<char> commands;
    for (std::string::const_iterator it = code.cend(); it != code.cbegin() - 1; --it) {
        commands.push(*it);
    }

    while (commands.top() != *(code.cend())) {
        char op = commands.top();
        commands.pop();

        switch (op)
        {
        case ',': {
            result_stack.push(*it_input);

            break;
        }
        case '.': {
            result_string += result_stack.top();
            result_stack.pop();

            break;
        }
        case '+': {
            char top = result_stack.top();
            result_stack.push((top + 1) % 256);

            break;
        }
        case '-': {
            char top = result_stack.top();
            std::cout << (int(top) - 1) << '\n';;
            result_stack.push((unsigned((int)top - 1)) % 256);

            break;
        }
        default: {
            std::cout << "ERROR: Unsupported symbol: " << op  << " (" << int(op) << ')' << '\n';
            return "";
        }
        }
    }

    return result_string;
}

int main() {
    // std::cout << ((unsigned(-1))%256) << '\n';

    std::cout << ((char) 0) << '\n';

    //echo until "0";
    std::string tw = "";
    tw.append(1,(char) 0);
    std::cout << int(brainLuck(",-.",tw)[0]) << '\n'; // "c"

    //echo until "255";
    tw = "c";
    tw.append(1,(char) 255);
    std::cout << brainLuck(",.",tw) << '\n'; // "c"

    //echo until "255";
    tw = "c";
    tw.append(1,(char)255);
    std::cout << brainLuck(",-.",tw) << '\n'; // "b"

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
    // std::string result_string;
    // result_string.append(1, (char)21);
    // std::cout << brainLuck(",>,<[>[->+>+<<]>>[-<<+>>]<<<-]>>.",dw << '\n'; // 

    return 0;
}