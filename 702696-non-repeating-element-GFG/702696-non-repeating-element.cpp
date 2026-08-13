class Solution {
  public:
    int firstNonRepeating(vector<int>& arr) {
        // code here
        unordered_map<int, int> res;
        for(int num : arr){
            res[num]++;
        }
        for(int num : arr){
            if(res[num] == 1){
                return num;
            }
        }
        return 0;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna