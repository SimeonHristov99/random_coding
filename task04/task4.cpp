#include <iostream>
#include <cmath>

long zeros(long n) {
    long result = 0;
    long denominator = 5;
    
    for (int k = 1; denominator <= n; ++k) {
        result += floor(n / denominator);
        denominator *= 5;
    }

    return result;
}

int main() {
    std::cout << zeros(0) << '\n'; // 0
    std::cout << zeros(6) << '\n'; // 1
    std::cout << zeros(30) << '\n'; // 7
    std::cout << zeros(100) << '\n'; // 24
    std::cout << zeros(1000) << '\n'; // 249
    std::cout << zeros(100000) << '\n'; // 24999
    std::cout << zeros(1000000000) << '\n'; // 249999998

    return 0;
}