class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();

        // dp[j] = maximum sum when we reach current row
        // and choose column j
        vector<int> dp(n);

        // First row: we can start from any column
        for (int j = 0; j < n; j++) {
            dp[j] = mat[0][j];
        }

        // Process remaining rows
        for (int i = 1; i < n; i++) {
            vector<int> next(n, 0);

            for (int j = 0; j < n; j++) {
                int best = 0;

                // Previous column must be different
                for (int k = 0; k < n; k++) {
                    if (k != j) {
                        best = max(best, dp[k]);
                    }
                }

                next[j] = mat[i][j] + best;
            }

            dp = next;
        }

        // Maximum sum in the last row
        return *max_element(dp.begin(), dp.end());
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna