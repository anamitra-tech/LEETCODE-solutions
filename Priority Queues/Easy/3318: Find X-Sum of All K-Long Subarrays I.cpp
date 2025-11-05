class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i + k <= n; i++) { // each subarray of size k
            unordered_map<int, int> freq;

            // 1️⃣ Count frequency in current window
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            // 2️⃣ Push into max-heap sorted by (frequency, then value)
            priority_queue<pair<int, int>> maxHeap; // {frequency, num}
            for (auto& [num, f] : freq) {
                maxHeap.push({f, num});
            }

            // 3️⃣ Pop top x elements and compute sum = num * freq
            int sum = 0;
            for (int cnt = 0; cnt < x && !maxHeap.empty(); cnt++) {
                auto [f, num] = maxHeap.top();
                maxHeap.pop();
                sum += num * f;  // ✅ Correct formula
            }

            result.push_back(sum);
        }

        return result;
    }
};
