class Solution {
  public:
    bool subArrayExists(vector<int>& arr) {
        // code here
        unordered_set<int> h;
        int sum = 0;
        for(int i =0; i < arr.size(); i++){
            sum += arr[i];
            if(h.find(sum) != h.end()){
                return true;
            }
            if(sum == 0){
                return true;
            }
            h.insert(sum);
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna