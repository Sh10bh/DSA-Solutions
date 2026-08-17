class Solution {
    int dp[501][501];
    vector<int> pref;
    
    int solve(vector<int>& stoneValue, int left, int right) {
        if (left == right) return 0;
        if (dp[left][right] != -1) return dp[left][right];
        
        int max_score = 0;
        for (int i = left; i < right; ++i) {
            int left_sum = pref[i + 1] - pref[left];
            int right_sum = pref[right + 1] - pref[i + 1];
            
            if (left_sum < right_sum) {
                max_score = max(max_score, left_sum + solve(stoneValue, left, i));
            } else if (right_sum < left_sum) {
                max_score = max(max_score, right_sum + solve(stoneValue, i + 1, right));
            } else {
                max_score = max(max_score, left_sum + max(solve(stoneValue, left, i), solve(stoneValue, i + 1, right)));
            }
        }
        
        return dp[left][right] = max_score;
    }
    
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        pref.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }
        memset(dp, -1, sizeof(dp));
        return solve(stoneValue, 0, n - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna