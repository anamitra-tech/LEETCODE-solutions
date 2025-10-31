long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int k = 2;  // as per problem statement
        deque<int> maxQ, minQ;
        long long result = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            while (!maxQ.empty() && nums[right] > maxQ.back())
                maxQ.pop_back();
            maxQ.push_back(nums[right]);

            while (!minQ.empty() && nums[right] < minQ.back())
                minQ.pop_back();
            minQ.push_back(nums[right]);

            while (maxQ.front() - minQ.front() > k) {
                if (nums[left] == maxQ.front()) maxQ.pop_front();
                if (nums[left] == minQ.front()) minQ.pop_front();
                ++left;
            }

            result += (right - left + 1);
        }

        return result;
    }
