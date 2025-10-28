        // Traverse and group elements by i + j
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                diagonals[i + j].push_back(nums[i][j]);
            }
        }

        vector<int> result;

        // Traverse diagonals in order
        for (auto& [key, vec] : diagonals) {
            reverse(vec.begin(), vec.end()); // because bottom-up
            result.insert(result.end(), vec.begin(), vec.end());
        }

        return result;
    }
