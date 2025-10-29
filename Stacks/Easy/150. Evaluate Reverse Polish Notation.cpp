class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop top 2 elements
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();

                // Apply operation
                if (token == "+") stk.push(a + b);
                if (token == "-") stk.push(a - b);
                if (token == "*") stk.push(a * b);
                if (token == "/") stk.push(a / b);
            } else {
                // Convert string to int and push
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};
