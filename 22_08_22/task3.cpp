// C++ 17 used

#include <utility>
#include <numeric>
#include <vector>

// Better approach
// static std::pair<int, int> sumFracts(std::vector<std::vector<int>> &l)
// {
//     int D = 1, N = 0;
//     for (auto i : l)
//         D *= i[1];
//     for (auto i : l)
//         N += (i[0] * D / i[1]);
//     return {N / std::__gcd(N, D), D / std::__gcd(N, D)};
// }

class SumFractions
{
private:
    static std::pair<int, int> add(const std::pair<int, int> &rat1, const std::pair<int, int> &rat2)
    {
        return {rat1.first * rat2.second + rat2.first * rat1.second, rat1.second * rat2.second};
    }

    static std::pair<int, int> normalize(const std::pair<int, int> &rat)
    {
        int gcd = std::gcd(rat.first, rat.second);

        return {rat.first / gcd, rat.second / gcd};
    }

public:
    static std::pair<int, int> sumFracts(std::vector<std::vector<int>> &l)
    {
        std::pair<int, int> sum = {0, 1};

        for (const std::vector<int> &rat : l)
        {
            sum = add(sum, {rat[0], rat[1]});
        }

        return normalize(sum);
    }
};
