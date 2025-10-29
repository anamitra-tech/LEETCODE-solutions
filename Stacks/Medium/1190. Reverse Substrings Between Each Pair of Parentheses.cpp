#include <bits/stdc++.h>
using namespace std;

string reverseParentheses(string s) {
    stack<char> stk;

    for (char c : s) {
        if (c == ')') {
            string temp = "";
            // pop until '('
            while (!stk.empty() && stk.top() != '(') {
                temp += stk.top();
                stk.pop();
            }
            stk.pop(); // remove '('

            // push reversed substring characters back
            for (char ch : temp)
                stk.push(ch);
        } 
        else {
            stk.push(c);
        }
    }

    // build final string from stack
    string ans = "";
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s = "(u(love)i)";
    cout << reverseParentheses(s) << endl; // Output: iloveu
    return 0;
}
