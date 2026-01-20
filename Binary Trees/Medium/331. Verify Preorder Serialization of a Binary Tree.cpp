class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;
        int n = preorder.size();
        int i = 0;
        
        while (i < n) {
            if (slots == 0) return false;

            if (preorder[i] == '#') {
                slots -= 1;
                i++;
            } else {
            
                while (i < n && preorder[i] != ',') i++;
                slots += 1; // 2 new slots - 1 = +1
            }

            // skip comma
            if (i < n && preorder[i] == ',') i++;
        }
        return slots == 0;
    }
};
