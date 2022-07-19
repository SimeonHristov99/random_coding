int solve(int n) {
    int out = 0;
    int result = 0;
    int current = 1;

    while(out < n) {
        ++out;
        result += current;
        current += 2;
    }

    return result;
}