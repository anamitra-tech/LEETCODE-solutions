#include <bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s) {
    unordered_map<char, char> mp = {{')', '('}};  // mapping of closing → opening
    stack<int> st;                                // store indices of '('
    unordered_set<int> invalid;                   // store indices to remove

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        // if it's an opening bracket, push index
        if (c == '(') {
            st.push(i);
        }

        // if it's a closing bracket
        else if (c == ')') {
            if (!st.empty() && s[st.top()] == mp[c]) {
                // found a valid matching '(' → ')'
                st.pop();
            } else {
                // no valid '(' for this ')'
                invalid.insert(i);
            }
        }
    }

    // any remaining '(' in stack are unmatched
    while (!st.empty()) {
        invalid.insert(st.top());
        st.pop();
    }

    // build the valid result string
    string result = "";
    for (int i = 0; i < s.size(); i++) {
        if (invalid.find(i) == invalid.end()) {
            result += s[i];
        }
    }

    return result;
}


