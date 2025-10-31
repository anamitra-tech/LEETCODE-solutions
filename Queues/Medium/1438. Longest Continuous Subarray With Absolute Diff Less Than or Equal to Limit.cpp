int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> maxQ, minQ;
        int left = 0, result = 0;

        for (int right = 0; right < n; ++right) {
            // Maintain maxQ (decreasing)
            while (!maxQ.empty() && nums[right] > maxQ.back())
                maxQ.pop_back();
            maxQ.push_back(nums[right]);

            // Maintain minQ (increasing)
            while (!minQ.empty() && nums[right] < minQ.back())
                minQ.pop_back();
            minQ.push_back(nums[right]);

            // If condition violates, shrink window from left
            while (!maxQ.empty() && !minQ.empty() && maxQ.front() - minQ.front() > limit) {
                if (maxQ.front() == nums[left]) maxQ.pop_front();
                if (minQ.front() == nums[left]) minQ.pop_front();
                ++left;
            }

            // Update max length
            result = max(result, right - left + 1);
        }

        return result;
    }
