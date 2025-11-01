class StockPrice {
private:
    int latestTime;
    unordered_map<int, int> timePrice;
    priority_queue<pair<int, int>> maxHeap; // {price, timestamp}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // min-heap

public:
    StockPrice() {
        latestTime = 0;
    }

    void update(int timestamp, int price) {
        timePrice[timestamp] = price;
        latestTime = max(latestTime, timestamp);

        maxHeap.push({price, timestamp});
        minHeap.push({price, timestamp});
    }

    int current() {
        return timePrice[latestTime];
    }

    int maximum() {
        // Clean outdated max values
        while (!maxHeap.empty() && timePrice[maxHeap.top().second] != maxHeap.top().first) {
            maxHeap.pop();
        }
        return maxHeap.top().first;
    }

    int minimum() {
        // Clean outdated min values
        while (!minHeap.empty() && timePrice[minHeap.top().second] != minHeap.top().first) {
            minHeap.pop();
        }
        return minHeap.top().first;
    }
};
