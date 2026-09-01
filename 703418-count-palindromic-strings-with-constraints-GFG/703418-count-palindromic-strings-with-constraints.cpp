class Solution {
public:
    int palindromicStrings(int n, int k) {
        long long total_ways = 0;
        long long MOD = 1e9 + 7;

        for (int L = 1; L <= n; ++L) {
            int req = (L + 1) / 2;

            if (req > k) {
                continue;
            }

            long long ways = 1;
            for (int i = 0; i < req; ++i) {
                ways = (ways * (k - i)) % MOD;
            }

            total_ways = (total_ways + ways) % MOD;
        }

        return total_ways;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna