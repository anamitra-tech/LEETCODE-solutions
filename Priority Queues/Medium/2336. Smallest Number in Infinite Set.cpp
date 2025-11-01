class SmallestInfiniteSet {
private:
    int curr;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_set<int> addedBack;

public:
    SmallestInfiniteSet() {
        curr = 1;
    }

    int popSmallest() {
        if (!minHeap.empty()) {
            int val = minHeap.top();
            minHeap.pop();
            addedBack.erase(val);
            return val;
        } else {
            return curr++;
        }
    }

    void addBack(int num) {
        // Only add back if num < curr and not already in the heap
        if (num < curr && addedBack.find(num) == addedBack.end()) {
            minHeap.push(num);
            addedBack.insert(num);
        }
    }
};
