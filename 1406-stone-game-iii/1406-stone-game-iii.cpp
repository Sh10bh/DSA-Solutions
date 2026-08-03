#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, -1e9);
        dp[n] = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            int take = 0;
            for (int j = 0; j < 3 && i + j < n; ++j) {
                take += stoneValue[i + j];
                dp[i] = max(dp[i], take - dp[i + j + 1]);
            }
        }
        
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna