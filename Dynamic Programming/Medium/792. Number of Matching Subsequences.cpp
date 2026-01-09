#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> freqMap;  // Stores character positions

        // Step 1: Store indices of each character in `s`
        for (int i = 0; i < s.length(); i++) {
            freqMap[s[i]].push_back(i);
        }

        int count = 0;

        // Step 2: Check each word if it is a subsequence
        for (string& word : words) {
            int prev = -1;
            bool isSubseq = true;

            for (char ch : word) {
                if (freqMap.find(ch) == freqMap.end()) {  // Character not in s
                    isSubseq = false;
                    break;
                }

                // Find the next occurrence of ch after `prev` using binary search
                auto it = upper_bound(freqMap[ch].begin(), freqMap[ch].end(), prev);
                if (it == freqMap[ch].end()) {  // No valid index found
                    isSubseq = false;
                    break;
                }
                prev = *it; // Move prev forward
            }

            if (isSubseq) count++;  // If word is a subsequence, increment count
        }

        return count;
    }
};
