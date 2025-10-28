int threeSumMulti(vector<int>& arr, int target) {
    const int MOD = 1e9 + 7;
    unordered_map<int, long long> freq;
    for (int x : arr) freq[x]++;

    long long ans = 0;

    // Get all unique numbers
    vector<int> nums;
    for (auto &[k, v] : freq) nums.push_back(k);
    sort(nums.begin(), nums.end()); // to handle x <= y <= z

    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int x = nums[i];
        for (int j = i; j < n; j++) {
            int y = nums[j];
            int z = target - x - y;

            if (!freq.count(z)) continue;
            if (z < y) continue; // ensure x <= y <= z

            if (x == y && y == z) {
                ans += freq[x] * (freq[x]-1) * (freq[x]-2) / 6;
            } 
            else if (x == y && y != z) {
                ans += freq[x] * (freq[x]-1) / 2 * freq[z];
            } 
            else if (x != y && y == z) {
                ans += freq[y] * (freq[y]-1) / 2 * freq[x];
            } 
            else if (x < y && y < z) {
                ans += freq[x] * freq[y] * freq[z];
            }
        }
    }

    return ans % MOD;
}
