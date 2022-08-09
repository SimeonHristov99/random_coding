#include <iostream>
#include <vector>
#include <stack>

typedef std::pair<int, int> Interval;

std::vector<Interval> non_intersecting(const std::vector<Interval> &intervals)
{
    std::vector<Interval> result;

    int len_intervals = intervals.size();

    std::stack<Interval> interval_stack;
    interval_stack.push(intervals[len_intervals - 1]);

    for (int i = len_intervals - 2; i >= 0; --i)
    {
        Interval &top = interval_stack.top();

        if (intervals[i].second < top.first)
        {
            interval_stack.push(intervals[i]);
        }
        else
        {
            while (!interval_stack.empty() && intervals[i].second >= interval_stack.top().first)
            {
                top = interval_stack.top();
                interval_stack.pop();
            }

            interval_stack.push({
                std::min(intervals[i].first, top.first),
                std::max(intervals[i].second, top.second)
            });
        }
    }

    while (!interval_stack.empty())
    {
        result.push_back(interval_stack.top());
        interval_stack.pop();
    }

    return result;
}

void test1()
{
    std::vector<Interval> intervals{{1, 5}, {2, 3}, {4, 6}, {7, 8}, {8, 10}, {12, 15}};

    for (const Interval &i : non_intersecting(intervals))
    {
        std::cout << '{' << i.first << ", " << i.second << "} ";
    }
    std::cout << '\n';
}

void test2()
{
    std::vector<Interval> intervals{{9, 10}, {10, 12}, {11, 13}, {14, 18}, {15, 18}};

    for (const Interval &i : non_intersecting(intervals))
    {
        std::cout << '{' << i.first << ", " << i.second << "} ";
    }
    std::cout << '\n';
}

int main(int argc, char const *argv[])
{
    test1(); // {1, 6} {7, 10} {12, 15}
    test2(); // {9, 13} {14, 18}

    return 0;
}
