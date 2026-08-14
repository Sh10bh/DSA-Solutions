class Solution {
    vector<vector<vector<int>>> dp;
    string num;
    int D;

    int solve(int idx, bool tight, bool isLeadingZero) {
        if (idx == num.length()) {
            return isLeadingZero ? 0 : 1;
        }

        if (dp[idx][tight][isLeadingZero] != -1) {
            return dp[idx][tight][isLeadingZero];
        }

        int limit = tight ? num[idx] - '0' : 9;
        int ans = 0;

        for (int digit = 0; digit <= limit; ++digit) {
            if (digit == D && !(D == 0 && isLeadingZero)) {
                continue;
            }

            ans += solve(idx + 1, 
                         tight && (digit == limit), 
                         isLeadingZero && (digit == 0));
        }

        return dp[idx][tight][isLeadingZero] = ans;
    }

public:
    int countWithout(int n, int d) {
        num = to_string(n);
        D = d;
        dp.assign(num.length(), vector<vector<int>>(2, vector<int>(2, -1)));

        return solve(0, true, true);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna