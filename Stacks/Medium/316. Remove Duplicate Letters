    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < s.size(); ++i)
            lastIndex[s[i] - 'a'] = i;

        vector<bool> seen(26, false);
        stack<char> stk;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (seen[c - 'a']) continue;

            // Pop from stack if:
            // 1. Current char is smaller than top of stack
            // 2. Top of stack char will appear later again
            while (!stk.empty() && c < stk.top() && lastIndex[stk.top() - 'a'] > i) {
                seen[stk.top() - 'a'] = false;
                stk.pop();
            }

            stk.push(c);
            seen[c - 'a'] = true;
        }

        string result;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }

// (!stk.empty() && c < stk.top() && lastIndex[stk.top() - 'a'] > i this means that if we encounter a character which is 
//lexographically smalleer than the one int he top of the stack then we must also see that the character is again reappearing
//in the aftermath so that we are safe to remove it 
