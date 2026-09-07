class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1000000007;
        vector<long long> end(26, 0);
        long long total = 0;
        for (char ch : s) {
            int idx = ch - 'a';
            long long newEnd = (total + 1) % MOD;
            total = ((total - end[idx] + newEnd) % MOD + MOD) % MOD;
            end[idx] = newEnd;
        }
        return (int)total;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna