#include <iostream>
#include <vector>

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr) {
        if (arr.size() == 0) {
            return {};
        }

        for (auto it = arr.begin(); it != arr.end() - 1;) {
            if (
                (it->compare("NORTH") == 0 && (it + 1)->compare("SOUTH") == 0)
                || (it->compare("SOUTH") == 0 && (it + 1)->compare("NORTH") == 0)
                || (it->compare("EAST") == 0 && (it + 1)->compare("WEST") == 0)
                || (it->compare("WEST") == 0 && (it + 1)->compare("EAST") == 0)
            ) {
                it = arr.erase(it);
                it = arr.erase(it);

                if (arr.size() == 0) {
                    return {};
                }

                it = arr.begin();
            } else {
                ++it;
            }
        }

        return arr;
    }
};

int main() {
    std::vector<std::string> d1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
    std::vector<std::string> ans1 = DirReduction::dirReduc(d1);
    for (const std::string& dir : ans1) {
        std::cout << dir << ' '; // "WEST"
    }
    std::cout << '\n';

    std::vector<std::string> d2 = {"NORTH","SOUTH","SOUTH","EAST","WEST","NORTH", "NORTH"};
    std::vector<std::string> ans2 = DirReduction::dirReduc(d2);
    for (const std::string& dir : ans2) {
        std::cout << dir << ' '; // "NORTH"
    }
    std::cout << '\n';

    d1 = {"NORTH"};
    ans1 = DirReduction::dirReduc(d1);
    for (const std::string& dir : ans1) {
        std::cout << dir << ' '; // "NORTH"
    }
    std::cout << '\n';

    d1 = {};
    ans1 = DirReduction::dirReduc(d1);
    for (const std::string& dir : ans1) {
        std::cout << dir << ' '; // {}
    }
    std::cout << '\n';

    d1 = {"NORTH","SOUTH"};
    ans1 = DirReduction::dirReduc(d1);
    for (const std::string& dir : ans1) {
        std::cout << dir << ' '; // {}
    }
    std::cout << '\n';

    return 0;
}

/*
A better/cleaner solution.

#include <string>
#include <vector>
#include <unordered_map>

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(const std::vector<std::string> &arr);
    static const std::unordered_map<std::string, std::string> oppositeWays;
};

const std::unordered_map<std::string, std::string> DirReduction::oppositeWays {
    {"EAST", "WEST"},
    {"WEST", "EAST"},
    {"NORTH", "SOUTH"},
    {"SOUTH", "NORTH"},
};


std::vector<std::string> DirReduction::dirReduc(const std::vector<std::string> &arr) {
    std::vector<std::string> result;
    for (const auto &way : arr) {
        if (result.empty() || result.back() != oppositeWays.at(way)) {
            result.push_back(way);
        }
        else {
            result.pop_back();
        }
    }
    return result;
}
*/