
class ArrayReader {
private:
    vector<int> arr;
public:
    ArrayReader(vector<int> data) { arr = data; }

    int get(int index) {
        if (index >= arr.size()) return INT_MAX; // simulating infinity
        return arr[index];
    }
};

int search(ArrayReader &reader, int target) {
    int start = 0, end = 1;

    // Step 1: Expand the search range exponentially
    while (reader.get(end) < target) {
        start = end;
        end = end * 2;
    }

    // Step 2: Binary search within the found range
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int val = reader.get(mid);

        if (val == target)
            return mid;
        else if (val < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1; // not found
}

        cout << "Element not found" << endl;

    return 0;
}
