#include <iostream>
#include <stack>

class Solution
{
private:
public:
    std::string makeGood(const std::string &s) const
    {
        std::string result;
        int res_len = 0;

        for (const char c : s)
        {
            if (
                res_len > 0 &&
                (result[res_len - 1] == ('A' + c - 'a')
                || result[res_len - 1] == ('a' + c - 'A')))
            {
                result.pop_back();
                --res_len;
            }
            else
            {
                result += c;
                ++res_len;
            }
        }

        return result;
    }
};

/**
 * Alternative
 class Solution {
public:
    string makeGood(string s) {
        string result;
        stack<char> st;

        for (const char c : s)
        {
            if (!st.empty())
            {
                char last_added = st.top();
                if (last_added == ('A' + c - 'a') || last_added == ('a' + c - 'A'))
                {
                    st.pop();
                }
                else
                {
                    st.push(c);
                }
            }
            else
            {
                st.push(c);
            }
        }

        while(!st.empty())
        {
            result.insert(0, 1, st.top());
            st.pop();
        }

        return result;
    }
};
*/

int main(int argc, char const *argv[])
{
    Solution s;

    std::cout << s.makeGood("leEeetcode") << '\n';
    std::cout << s.makeGood("abBAcC") << '\n';
    std::cout << s.makeGood("s") << '\n';

    return 0;
}
