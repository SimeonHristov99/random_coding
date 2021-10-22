#include <iostream>
#include <vector>
#include <algorithm>

template<class TYPE>
int getLengthOfMissingArray(std::vector<std::vector<TYPE>> arrayOfArrays)
{
    int size = arrayOfArrays.size();
    
    std::sort(arrayOfArrays.begin(), arrayOfArrays.end(), [](auto x, auto y){ return x.size() < y.size(); });

    for (int i = 0; i < size - 1; ++i) {
        int current_size = arrayOfArrays[i].size();

        if (current_size == 0) {
            return 0;
        }

        if (current_size != arrayOfArrays[i + 1].size() - 1) {
            return current_size + 1;
        }
    }

    return 0;
}

int main() {
    std::vector<std::vector<int>> v{{1, 2}, {4, 5, 1, 1}, {1}, {5, 6, 7, 8, 9}};

    std::cout << getLengthOfMissingArray(v) << '\n';

    return 0;
}