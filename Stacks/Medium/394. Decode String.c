class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string num = ""; // to collect digits for repetition

        for (char c : s) {
            if (isdigit(c)) {
                num += c;  // build full number
            }
            else if (c == '[') {
                st.push(num); // push number before starting a group
                st.push("["); // marker
                num = "";
            }
            else if (isalpha(c)) {
                string temp(1, c);
                st.push(temp); // push characters directly
            }
            else if (c == ']') {
                // Pop substring until '['
                string decoded = "";
                while (!st.empty() && st.top() != "[") {
                    decoded = st.top() + decoded;
                    st.pop();
                }
                st.pop(); // remove '['

                // Get number (repetitions)
                int repeat = stoi(st.top());
                st.pop();

                // Repeat the substring
                string repeated = "";
                for (int i = 0; i < repeat; i++)
                    repeated += decoded;

                // Push the expanded substring back
                st.push(repeated);
            }
        }

        // Final decoded string
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};
