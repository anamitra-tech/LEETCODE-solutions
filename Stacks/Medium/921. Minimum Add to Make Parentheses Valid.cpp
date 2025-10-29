class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;  // tracks unmatched '('
        int add = 0;   // tracks unmatched ')'

        for (char c : s) {
            if (c == '(') {
                open++;
            } else {  // c == ')'
                if (open > 0) {
                    open--;  // match with an open '('
                } else {
                    add++;   // no matching '(', need to add one
                }
            }
        }

        // total insertions needed = unmatched '(' + unmatched ')'
        return add + open;
    }
};
