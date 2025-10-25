
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Push all elements into the heap
        for (int num : nums) {
            minHeap.push(num);
        }

        // Pop and add to result to get sorted order
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        return result;
    }

//quicksort wont be used as the worstcase senario is big o of n2
//and the worst case of min and max heap is big o of nlogn
