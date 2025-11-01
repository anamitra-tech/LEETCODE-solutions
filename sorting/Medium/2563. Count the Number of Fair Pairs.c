long long countPairs(vector<int>& nums, long long bound) {
    long long cnt = 0;
    int i = 0, j = nums.size() - 1;
    while (i < j) {
        if (nums[i] + nums[j] <= bound) {
            cnt += (j - i);
            i++;
        } else {
            j--;
        }
    }
    return cnt;
}

long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    return countPairs(nums, upper) - countPairs(nums, lower - 1);
}

