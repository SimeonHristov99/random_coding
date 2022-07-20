int solve(vector<int>& rooms, int target) {
    for(const int r : rooms) {
        if(r >= target) {
            return r;
        }
    }

    return -1;
}