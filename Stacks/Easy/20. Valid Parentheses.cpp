class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mapping = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (mapping.count(c)) {  // if it's a closing bracket
                if (!stk.empty() && stk.top() == mapping[c]) {
                    stk.pop();
                } else {
                    return false;
                }
            } else {  // if it's an opening bracket
                stk.push(c);
            }
        }

        return stk.empty();  // valid if stack is empty
    }
};
