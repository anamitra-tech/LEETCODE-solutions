
    unordered_map<char, int> getDigitFrequency(int num) {
        unordered_map<char, int> freq;
        string s = to_string(num);
        for (char ch : s) {
            freq[ch]++;
        }
        return freq;
    }

    bool reorderedPowerOf2(int n) {
        unordered_map<char, int> targetFreq = getDigitFrequency(n);

        for (int i = 0; i < 31; ++i) {
            int power = 1 << i; // 2^i
            if (getDigitFrequency(power) == targetFreq) {
                return true;
            }
        }

        return false;
    }
