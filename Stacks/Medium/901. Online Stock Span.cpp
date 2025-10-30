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
//here pair is imp to keep track of the count as once popped it will loose track so to keep that track it is imp
