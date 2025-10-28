int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap;
        int maxVal = -1;

        for (int num : nums) {
            int digitSum = sumOfDigits(num);
            
            if (digitSumMap.find(digitSum) != digitSumMap.end()) {
                maxVal = max(maxVal, digitSumMap[digitSum] + num);
            }
            
            digitSumMap[digitSum] = max(digitSumMap[digitSum], num);
        }

        return maxVal;
    }
