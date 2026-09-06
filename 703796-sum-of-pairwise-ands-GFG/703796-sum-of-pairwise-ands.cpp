class Solution {
public:
    long long pairAndSum(vector<int> &arr) {
        long long total = 0;

        for (int b = 0; b < 32; ++b) {
            long long count = 0;

            for (int x : arr) {
                if (x & (1 << b)) {
                    count++;
                }
            }

            long long pairs = (count * (count - 1)) / 2;
            total += pairs * (1LL << b);
        }

        return total;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna