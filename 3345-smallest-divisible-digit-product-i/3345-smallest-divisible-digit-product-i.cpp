class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int temp = n;
            int prod = 1;
            
            while (temp > 0) {
                prod *= temp % 10;
                temp /= 10;
            }
            
            if (prod % t == 0) {
                return n;
            }
            n++;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna