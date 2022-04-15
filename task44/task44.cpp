#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::max;
using std::min;
using std::pair;
using std::set;
using std::vector;

class Solution
{
private:
    void print_pairs(const vector<vector<pair<int, int>>> &all_pairs)
    {
        for (const vector<pair<int, int>> &x : all_pairs)
        {
            for (const auto a : x)
            {
                std::cout << '(' << a.first << ' ' << a.second << ") ";
            }
            std::cout << '\n';
        }
    }

    // Credits: https://stackoverflow.com/questions/5360220/how-to-split-a-list-into-pairs-in-all-possible-ways
    vector<int> remove_ith(const vector<int> &nums, int i)
    {
        vector<int> result;
        int nums_len = nums.size();
        for (int j = 0; j < nums_len; j++)
        {
            if (j != i)
            {
                result.push_back(nums[j]);
            }
        }
        return result;
    }

    vector<vector<pair<int, int>>> generate_all_pairs(const vector<int> &nums)
    {
        vector<vector<pair<int, int>>> result;

        int nums_len = nums.size();
        if (nums_len < 2)
        {
            result.push_back({});
            return result;
        }

        int n = nums[0];

        for (int i = 1; i < nums_len; ++i)
        {
            std::pair<int, int> p = {n, nums[i]};

            vector<int> num_no_0 = remove_ith(nums, 0);
            num_no_0 = remove_ith(num_no_0, i - 1);
            for (vector<pair<int, int>> rest : generate_all_pairs(num_no_0))
            {
                int rest_size = rest.size();
                vector<pair<int, int>> p_vec(1 + rest_size);
                p_vec[0] = p;
                p_vec.insert(p_vec.begin() + 1, rest.begin(), rest.end());
                while (rest_size > 0)
                {
                    p_vec.pop_back();
                    --rest_size;
                }
                result.push_back(p_vec);
            }
        }

        return result;
    }

    vector<int> get_sums(const vector<pair<int, int>> &p)
    {
        vector<int> result;

        for (const pair<int, int> &pr : p)
        {
            result.push_back(pr.first + pr.second);
        }

        return result;
    }

    int get_maxes(const vector<vector<pair<int, int>>> &all_pairs)
    {
        vector<int> result;

        for (const vector<pair<int, int>> &vp : all_pairs)
        {
            vector<int> sums = get_sums(vp);
            std::sort(sums.begin(), sums.end(), std::greater<int>());
            result.push_back(sums[0]);
        }

        std::sort(result.begin(), result.end());
        return result[0];
    }

public:
    int minPairSum(const vector<int> &nums)
    {
        vector<vector<pair<int, int>>> all_pairs = generate_all_pairs(nums);

        // print_pairs(all_pairs);

        return get_maxes(all_pairs);
    }
};

TEST_CASE("Test 1")
{
    vector<int> v{3,5,2,3};
    Solution s;

    CHECK_EQ(s.minPairSum(v), 7);
}

TEST_CASE("Test 2")
{
    vector<int> v{3,5,4,2,4,6};
    Solution s;

    CHECK_EQ(s.minPairSum(v), 8);
}

TEST_CASE("Test 3")
{
    vector<int> v{3, 5, 4, 2, 4, 6};
    Solution s;

    CHECK_EQ(s.minPairSum(v), 8);
}
