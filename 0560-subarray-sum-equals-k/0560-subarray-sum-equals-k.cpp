class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> h;
        int sum = 0;
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == k){
                count++;
            }
            int target = sum - k;
            if(h.find(target) != h.end()){
                count += h[target];
            }
            h[sum]++;
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna