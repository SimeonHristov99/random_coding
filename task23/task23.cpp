#include <iostream>
#include <stack>
#include <string>

void reverseWordOrder(const std::string &input)
{
    std::stack<std::string> s;

    int len_input = input.size();
    for (int i = 0; i < len_input; i++)
    {
        std::string currentWord;
        while (i < len_input && input[i] != ' ')
        {
            currentWord += input[i++];
        }
        s.push(currentWord);
    }

    while(!s.empty())
    {
        std::cout << s.top() << ' ';
        s.pop();
    }
    std::cout << '\n';
}

int main()
{
    std::string s = "Technical Interview Preparation";
    reverseWordOrder(s);

    return 0;
}