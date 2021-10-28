#include <iostream>
#include <vector>
#include <stack>

std::string brainLuck(const std::string &code, const std::string &input)
{
    int len_input = input.length();
    int len_code = code.length();

    if (len_input == 0)
    {
        std::cout << "Input was empty!\n";
        return "";
    }

    if (len_code == 0)
    {
        std::cout << "Code was empty!\n";
        return input;
    }

    // col1: indices of openning brackets
    // col2: indices of closing brackets
    // for ,[.[-],] this is [[1, 7], [3, 5]]
    std::vector<std::vector<int>> brackets;

    std::string result_string;
    // result_string.resize(len_input, '\0');

    std::string::const_iterator it_input = input.cbegin();

    for (int i = 0; i < len_code; ++i)
    {
        if (code[i] == '[')
        {
            brackets.push_back({i, -1});
        }
        else if (code[i] == ']')
        {
            for (int j = brackets.size() - 1; j >= 0; --j)
            {
                if (brackets[j][1] == -1)
                {
                    brackets[j][1] = i;
                    break;
                }
            }
        }
    }

    char data_pointer = '0';
    for (int i = 0; i < len_code; ++i)
    {
        switch (code[i])
        {
        case ',':
        {
            data_pointer = *it_input;
            ++it_input;

            break;
        }
        case '.':
        {
            result_string += data_pointer;

            break;
        }
        case '+':
        {
            data_pointer = (data_pointer + 1) % 256;

            break;
        }
        case '-':
        {
            data_pointer = (char)(unsigned((int)data_pointer - 1)) % 256;

            break;
        }
        case '[':
        {
            if ((int)data_pointer == 0)
            {
                for (auto b : brackets) {
                    if (b[0] == i) {
                        i = b[1];
                        break;
                    }
                }
            }

            break;
        }
        case ']':
        {
            if ((int)data_pointer != 0)
            {
                for (auto b : brackets) {
                    if (b[1] == i) {
                        i = b[0];
                        break;
                    }
                }
            }

            break;
        }
        default:
        {
            std::cout << "ERROR: Unsupported symbol: " << code[i] << " (" << int(code[i]) << ')' << '\n';
            return "";
        }
        }
    }

    return result_string;
}

int main()
{
    //echo until "255";
    std::string tw = "c";
    tw.append(1, (char)255);
    std::cout << brainLuck(",.", tw) << '\n'; // "c"

    //echo until "255";
    tw = "c";
    tw.append(1, (char)255);
    std::cout << brainLuck(",-.", tw) << '\n'; // "c"

    //echo until "255";
    tw = "c";
    tw.append(1, (char)255);
    std::cout << brainLuck(",+.", tw) << '\n'; // "d"

    //echo until "255";
    tw = "c0";
    tw.append(1, (char)255);
    std::cout << brainLuck(",.,[.", tw) << '\n'; // "cc"

    // //echo until "255";
    // tw = "codewars";
    // tw.append(1, (char)255);
    // std::cout << brainLuck(",+[-.,+]", tw) << '\n'; // "codewars"

    //echo until "0";
    // std::string mw = "codewars";
    // mw.append(1, (char)0);
    // // endless recursion
    // std::cout << brainLuck(",[.[-],]", mw) << '\n'; // "codewars"

    //two number multiplier
    // std::string dw;
    // dw.append(1, (char) 7);
    // dw.append(1, (char) 3);
    // std::string result_string;
    // result_string.append(1, (char)21);
    // std::cout << brainLuck(",>,<[>[->+>+<<]>>[-<<+>>]<<<-]>>.",dw << '\n'; //

    return 0;
}