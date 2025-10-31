class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.size();

        // Step 1: Fill initial queues with indices of senators
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }

        // Step 2: Simulate the rounds
        while (!radiant.empty() && !dire.empty()) {
            int rIndex = radiant.front();
            int dIndex = dire.front();
            radiant.pop();
            dire.pop();

            // Whoever's index is earlier acts first
            if (rIndex < dIndex)
                radiant.push(rIndex + n);  // Radiant senator survives and re-enters next round
            else
                dire.push(dIndex + n);     // Dire senator survives and re-enters next round
        }

        // Step 3: Return the winning party
        return radiant.empty() ? "Dire" : "Radiant";
    }
};
