class Solution {
  public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        const int LIMIT = 2048; // since nums[i] < n <= 1500 < 2^11
        
        bitset<LIMIT> pairXor;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor.set(nums[i] ^ nums[j]);
            }
        }
        
        bitset<LIMIT> result;
        for (int k = 0; k < n; k++) {
            for (int b = pairXor._Find_first(); b != LIMIT; b = pairXor._Find_next(b)) {
                result.set(b ^ nums[k]);
            }
        }
        
        return result.count();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna