string removeKdigits(string num, int k) {
        stack<char> stk;

        for (char c : num) {
            while (!stk.empty() && k > 0 && stk.top() > c) {
                stk.pop();
                k--;
            }
            stk.push(c);
        }

        // Remove remaining digits from end if k > 0
        while (k > 0 && !stk.empty()) {
            stk.pop();
            k--;
        }

        // Build the result string from the stack
        string result = "";
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        reverse(result.begin(), result.end());

        // Remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') i++;

        result = result.substr(i);
        return result.empty() ? "0" : result;
    }
