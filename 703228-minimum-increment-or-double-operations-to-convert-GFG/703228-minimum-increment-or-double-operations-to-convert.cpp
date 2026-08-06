class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        int ops = 0;
        int max_val = 0;
        
        for (int num : arr) {
            max_val = std::max(max_val, num);
            while (num > 0) {
                ops += (num & 1);
                num >>= 1;
            }
        }
        
        while (max_val > 1) {
            ops++;
            max_val >>= 1;
        }
        
        return ops;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna