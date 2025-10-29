
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int j = 0;  // pointer for popped array

        for (int val : pushed) {
            stk.push(val);  // push the value

            // while top of stack matches the popped[j], pop it
            while (!stk.empty() && stk.top() == popped[j]) {
                stk.pop();
                j++;  // move to next element in popped
            }
        }

        // if all elements were matched, stack should be empty
        return stk.empty();
    }
