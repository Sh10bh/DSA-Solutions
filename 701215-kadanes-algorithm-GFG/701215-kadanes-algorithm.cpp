class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int maxsum = arr[0];
        int res = arr[0];
        for(int i = 1; i < arr.size(); i++){
            maxsum = max(maxsum + arr[i], arr[i]);
            res = max(maxsum, res);
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna