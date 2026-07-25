class Solution {
public:
    int maxProduct(int n) {
        int d1 = 0, d2 = 0;
        while (n) {
            int d = n % 10;
            n /= 10;
            if (d >= d1) {
                d2 = d1;
                d1 = d;
            } else if (d > d2) {
                d2 = d;
            }
        }
        return d1 * d2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna