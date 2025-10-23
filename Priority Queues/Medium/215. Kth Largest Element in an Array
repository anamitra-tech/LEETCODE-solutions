    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min Heap
        
        for (int num : nums) {
            minHeap.push(num); // Push current element

            // Keep only k largest elements
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the smallest
            }
        }
        
        return minHeap.top(); // The k-th largest element
    }
