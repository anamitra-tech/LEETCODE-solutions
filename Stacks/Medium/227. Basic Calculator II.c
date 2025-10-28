  int calculate(string s) {
        stack<int> stk;
        int num = 0;
        char lastOp = '+'; // Keeps track of last operator
        s += '+'; // Append '+' to process the last number

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0'); // Build multi-digit number
            }

            if (!isdigit(s[i]) && !isspace(s[i])) {
                // Perform the last operation
                if (lastOp == '+') {
                    stk.push(num);
                } else if (lastOp == '-') {
                    stk.push(-num);
                } else if (lastOp == '*') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top * num);
                } else if (lastOp == '/') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top / num);
                }
                
                lastOp = s[i]; // Update last operator
                num = 0; // Reset num
            }
        }

        // Sum up all values in stack
        int result = 0;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }

        return result;
    }

          //last op is used so that num and top could be used and not s[i+1] 
