class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;  // store indices
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            // sentinel: when i == n, we assume height = 0 to flush the stack
            int currHeight = (i == n ? 0 : heights[i]);

            // when current bar is smaller, process top (NGE found)
            while (!stk.empty() && currHeight < heights[stk.top()]) {
                int top = stk.top();
                stk.pop();

                int right = i;  // next smaller element index
                int left = stk.empty() ? -1 : stk.top();  // previous smaller index

                int width = right - left - 1;
                int area = heights[top] * width;

                maxArea = max(maxArea, area);
            }

            stk.push(i);
        }

        return maxArea;
    }
};
