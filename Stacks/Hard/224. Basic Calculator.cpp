class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int result = 0, num = 0, sign = 1;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            }
            else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            }
            else if (c == '(') {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            }
            else if (c == ')') {
                result += sign * num;
                num = 0;
                int prevSign = stk.top(); stk.pop();
                int prevResult = stk.top(); stk.pop();
                result = prevResult + prevSign * result;
            }
        }

        result += sign * num;
        return result;
    }
};
