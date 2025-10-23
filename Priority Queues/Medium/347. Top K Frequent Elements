
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++; // count frequency
        }

        // Max heap: pair<frequency, number>
        priority_queue<pair<int, int>> max_heap;
        for (auto& p : freqMap) {
            max_heap.push({p.second, p.first});
        }

        vector<int> result;
        while (k > 0 && !max_heap.empty()) {
            result.push_back(max_heap.top().second); // push the number
            max_heap.pop();
            k--;
        }
        return result;
    }
