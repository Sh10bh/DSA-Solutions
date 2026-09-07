class Solution {
public:
    int minCount(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> next(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> curr(n + 1, vector<int>(n + 1, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int incLast = -1; incLast < n; incLast++) {
                for (int decLast = -1; decLast < n; decLast++) {
                    int ans = 1 + next[incLast + 1][decLast + 1];
                    if (incLast == -1 || arr[idx] > arr[incLast])
                        ans = min(ans, next[idx + 1][decLast + 1]);
                    if (decLast == -1 || arr[idx] < arr[decLast])
                        ans = min(ans, next[incLast + 1][idx + 1]);

                    curr[incLast + 1][decLast + 1] = ans;
                }
            }
            next = curr;
        }

        return next[0][0];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna