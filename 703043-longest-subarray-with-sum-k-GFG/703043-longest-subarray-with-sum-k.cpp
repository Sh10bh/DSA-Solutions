class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> s;
        int sum = 0;
        int res = 0;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            if(sum == k){
                res = i + 1;
            }
            if(s.find(sum) == s.end()){
                s.insert({sum, i});
            } 
            if(s.find(sum - k) != s.end()){
                res = max(res, i - s[sum - k]);
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna