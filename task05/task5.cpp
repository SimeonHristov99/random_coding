#include <iostream>
#include <vector>

int** multiplication_table_array(const int n) {
    int** table = new int*[n];

    for (int row = 0; row < n; ++row) {
        table[row] = new int[n];
        for (int col = 0; col < n; ++col) {
            table[row][col] = (row + 1) * (col + 1);
        }
    }
    
    return table;
}

std::vector<std::vector<int>> multiplication_table(int n){
    std::vector<std::vector<int>> result;

    for (int row = 0; row < n; ++row) {
        result.push_back({});
        for (int col = 0; col < n; ++col) {
            result[row].push_back((row + 1) * (col + 1));
        }
    }

    return result;
}

int main() {
    const int n = 3;

    std::cout << "Version with std::vector:\n";
    std::vector<std::vector<int>> r = multiplication_table(n);

    for (std::vector<int> n : r) {
        for (int m : n) {
            std::cout << m << ' ';
        }
        std::cout << '\n';
    }

    std::cout << "Version with arrays:\n";
    int** table = multiplication_table_array(n);

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            std::cout << table[row][col] << ' ';
        }
        std::cout << '\n';
    }

    for (int row = 0; row < n; ++row) {
        delete[] table[row];
        table[row] = nullptr; 
    }

    delete[] table;
    table = nullptr;

    return 0;
}