class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int total_xor = 0;
        bool has_nonzero = false;
        
        for (int i = 0; i < n; ++i) {
            total_xor ^= nums[i];
            if (nums[i] != 0) {
                has_nonzero = true;
            }
        }
        
        if (!has_nonzero) {
            return 0;
        }
        
        if (total_xor != 0) {
            return n;
        }
        
        return n - 1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna