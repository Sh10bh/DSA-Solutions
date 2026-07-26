class Solution {
public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        vector<vector<int>> res;
        int n = arr.size();
        int i = 0, levelSize = 1;
        while (i < n) {
            int cnt = min(levelSize, n - i);
            vector<int> level(arr.begin() + i, arr.begin() + i + cnt);
            sort(level.begin(), level.end());
            res.push_back(level);
            i += cnt;
            levelSize *= 2;
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna