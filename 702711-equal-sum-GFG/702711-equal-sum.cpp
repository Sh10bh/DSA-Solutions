class Solution {
  public:
    string equilibrium(vector<int> &arr) {
        // code here
        int sum = 0;
        for(int num : arr){
            sum += num;
        }
        int left_sum = 0;
        for(int i = 0; i < arr.size(); i++){
            int right_sum = sum - left_sum - arr[i];
            if(left_sum == right_sum){
                return "true";
            }
            left_sum += arr[i];
        }
        return "false";
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna