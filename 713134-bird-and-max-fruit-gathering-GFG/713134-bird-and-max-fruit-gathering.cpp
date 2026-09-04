class Solution {
public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();
        if (n == 0 || m == 0) {
            return 0;
        }

        if (m >= n) {
            int total = 0;
            for (int x : arr) {
                total += x;
            }
            return total;
        }

        int current_sum = 0;
        for (int i = 0; i < m; ++i) {
            current_sum += arr[i];
        }

        int max_sum = current_sum;

        for (int i = 1; i < n; ++i) {
            current_sum -= arr[i - 1];
            current_sum += arr[(i + m - 1) % n];

            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }

        return max_sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna