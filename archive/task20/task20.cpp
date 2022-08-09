#include <iostream>
#include <fstream>
#include <stack>

int factorial(int x)
{
    int result = 1;

    for (int i = 2; i <= x; ++i)
    {
        result *= i;
    }

    return result;
}

int calc_expression(std::string input)
{
    std::stack<int> numbers;
    std::stack<char> operations;
    std::stack<char> brackets;

    int len_input = input.size();

    for (int i = 0; i < len_input; ++i)
    {
        if (input[i] == 'f' || input[i] == 'g' || input[i] == 'm')
        {
            operations.push(input[i]);
        }
        else if ('0' <= input[i] && input[i] <= '9')
        {
            int number = 0;

            while ('0' <= input[i] && input[i] <= '9')
            {
                number = number * 10 + (input[i] - '0');
                ++i;
            }

            --i;

            numbers.push(number);
        }
        else if (input[i] == '(')
        {
            brackets.push(input[i]);
        }
        else if (input[i] == ')')
        {
            char operation = operations.top();
            operations.pop();

            if (operation == 'g')
            {
                int top = numbers.top();
                numbers.pop();
                numbers.push(factorial(top % 5));
            }
            else if (operation == 'f')
            {
                int top = numbers.top();
                numbers.pop();
                numbers.push((top * top) % 100);
            }
            else if (operation == 'm')
            {
                int y = numbers.top();
                numbers.pop();

                int x = numbers.top();
                numbers.pop();

                numbers.push(std::min(x, y));
            }
        }
    }

    return numbers.top();
}

void evaluate(const char *filename)
{
    std::string line;

    std::ifstream fin(filename);
    if (!fin)
    {
        std::cout << "ERROR: Could not open file!\n";
        return;
    }

    std::getline(fin, line);

    while (std::getline(fin, line))
    {
        std::cout << line << " = " << calc_expression(line) << '\n';
    }

    fin.close();
}

int main(int argc, char const *argv[])
{
    evaluate("./input.txt"); // should be 25, 24, 76

    return 0;
}
