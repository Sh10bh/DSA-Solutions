class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int window_sum = 0;
        int max_sum = 0;
        for(int i = 0; i < k; i++){
            window_sum += arr[i];
        }
        max_sum = window_sum;
        for(int i = k; i < arr.size(); i++){
            window_sum = window_sum + arr[i] - arr[i-k];
            max_sum = max(max_sum, window_sum);
        }
        return max_sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna