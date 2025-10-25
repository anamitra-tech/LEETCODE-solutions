vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // Max heap: store {distance, index}
    priority_queue<pair<int, int>> pq;
    
    for (int i = 0; i < points.size(); i++) {
        int dist2 = points[i][0]*points[i][0] + points[i][1]*points[i][1];
        pq.push({dist2, i});
        if (pq.size() > k)
            pq.pop(); // remove farthest point
    }
    
    vector<vector<int>> result;
    while (!pq.empty()) {
        result.push_back(points[pq.top().second]);
        pq.pop();
    }
    
    return result;
}
