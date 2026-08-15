class Solution {
public:
    int minProd(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        long long prod = 1;
        int count_zero = 0;
        int count_neg = 0;
        int max_neg = -1000000;
        int min_pos = 1000000;

        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0) {
                count_zero++;
                continue;
            }
            if (arr[i] < 0) {
                count_neg++;
                max_neg = max(max_neg, arr[i]);
            } else {
                min_pos = min(min_pos, arr[i]);
            }
            prod *= arr[i];
        }

        if (count_zero == n) return 0;

        if (count_neg % 2 == 0) {
            if (count_neg == 0) {
                if (count_zero > 0) return 0;
                return min_pos;
            } else {
                prod /= max_neg;
            }
        }

        return prod;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna