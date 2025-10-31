class Solution {
public:
    int jos(int n, int k) {
        if (n == 1) {
            return 0; // Base case: when only one person remains, they are at index 0.
        } else {
            return (jos(n - 1, k) + k) % n; // Recursive call to calculate the winner position.
        }
    }

    int findTheWinner(int n, int k) {
        // Call the recursive function to find the winner (position starts from 0).
        int winner = jos(n, k);
        
        // Since the result is 0-indexed, we add 1 to make it 1-indexed.
        return winner + 1;
    }
};
