class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int max_len = 0;
        unordered_map<int, int> a;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                sum += -1;
            }
            else{
                sum += 1;
            }
            if(sum == 0){
                max_len = i + 1;
            }
            if(a.find(sum) != a.end()){
                max_len = max(max_len, i-a[sum]);
            }
            else{
                a[sum] = i;
            }
        }
        return max_len;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna