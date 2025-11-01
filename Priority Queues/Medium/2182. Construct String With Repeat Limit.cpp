#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // Step 1: Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Use a max heap (priority queue) to get the largest lexicographical character first
        priority_queue<char> maxHeap;
        for (auto it : freq) {
            maxHeap.push(it.first);
        }

        string result = "";

        // Step 3: Process characters from the max heap
        while (!maxHeap.empty()) {
            char first = maxHeap.top(); // Get the largest character
            maxHeap.pop();

            int useCount = min(freq[first], repeatLimit); // Use `first` up to `repeatLimit`
            result.append(useCount, first);
            freq[first] -= useCount;

            if (freq[first] > 0) { // If `first` still has remaining occurrences, we need a separator
                if (maxHeap.empty()) break; // No more unique characters left to act as a separator

                char second = maxHeap.top(); // Get the next largest character
                maxHeap.pop();

                result.push_back(second); // Use one instance of `second` as a separator
                freq[second]--;

                // If `second` still has occurrences left, push it back into the heap
                if (freq[second] > 0) {
                    maxHeap.push(second);
                }

                // Push `first` back into the heap since it still has remaining occurrences
                maxHeap.push(first);
            }
        }

        return result;
    }
};
