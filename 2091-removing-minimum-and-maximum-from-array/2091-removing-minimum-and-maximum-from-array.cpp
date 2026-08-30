class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        
        int min_idx = 0;
        int max_idx = 0;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[min_idx]) {
                min_idx = i;
            }
            if (nums[i] > nums[max_idx]) {
                max_idx = i;
            }
        }
        
        int i = min(min_idx, max_idx);
        int j = max(min_idx, max_idx);
        
        int front_only = j + 1;
        int back_only = n - i;
        int both_sides = (i + 1) + (n - j);
        
        return min({front_only, back_only, both_sides});
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna