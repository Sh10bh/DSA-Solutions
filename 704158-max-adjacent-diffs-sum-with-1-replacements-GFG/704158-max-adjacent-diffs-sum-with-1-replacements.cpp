class Solution {
public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        int prev_orig = 0;
        int prev_one = 0;

        for (int i = 1; i < n; ++i) {
            int curr_orig = max(prev_orig + abs(arr[i] - arr[i - 1]), prev_one + abs(arr[i] - 1));
            int curr_one = max(prev_orig + abs(1 - arr[i - 1]), prev_one);

            prev_orig = curr_orig;
            prev_one = curr_one;
        }

        return max(prev_orig, prev_one);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna