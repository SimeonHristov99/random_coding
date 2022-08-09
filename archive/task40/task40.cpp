#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::string;
using std::vector;

class Solution
{
public:
    bool matches(const string &s, const string &p)
    {
        int len_p = p.length();
        map<char, char> map_s_p;
        map<char, char> map_p_s;

        for (int i = 0; i < len_p; ++i)
        {
            std::map<char, char>::iterator it_s_p = map_s_p.find(s[i]);
            std::map<char, char>::iterator it_p_s = map_p_s.find(p[i]);

            if (
                it_s_p != map_s_p.end() && it_s_p->second != p[i]
                || it_p_s != map_p_s.end() && it_p_s->second != s[i])
            {
                return false;
            }

            map_s_p.insert({s[i], p[i]});
            map_p_s.insert({p[i], s[i]});
        }

        return true;
    }

    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> result;

        for (const string &w : words)
        {
            if (matches(w, pattern))
            {
                result.push_back(w);
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{

    vector<string> words{"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    string pattern = "abb";

    Solution s;

    vector<string> res = s.findAndReplacePattern(words, pattern);

    for (const string &s : res)
    {
        std::cout << s << '\n';
    }

    return 0;
}
