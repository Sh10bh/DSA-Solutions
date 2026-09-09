class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long threshold = 1000;
        for (int i = 0; i < 5; i++) {
            if (n >= threshold) {
                ans += n - threshold + 1;
            }
            threshold *= 1000;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna