class StockSpanner {
public:
    stack<pair<int, int>> stk; // (price, span)

    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!stk.empty() && stk.top().first <= price) {
            span += stk.top().second;
            stk.pop();
        }
        stk.push({price, span});
        return span;
    }
};
