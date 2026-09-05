class Solution {
public:
    int longestSubseq(vector<int>& arr) {
        if (arr.empty()) return 0;

        int max_val = 0;
        for (int x : arr) {
            if (x > max_val) {
                max_val = x;
            }
        }

        vector<int> dp(max_val + 2, 0);
        int max_len = 0;

        for (int x : arr) {
            int prev_len = (x - 1 >= 0) ? dp[x - 1] : 0;
            int next_len = (x + 1 <= max_val) ? dp[x + 1] : 0;

            dp[x] = max(prev_len, next_len) + 1;

            if (dp[x] > max_len) {
                max_len = dp[x];
            }
        }

        return max_len;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna