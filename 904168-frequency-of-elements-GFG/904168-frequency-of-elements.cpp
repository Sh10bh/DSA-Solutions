class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here
        map<int , int> h;
        for(int x : arr){
            h[x]++;
        }
        vector<vector<int>> res;
        for(auto e : h){
            res.push_back({e.first,e.second});
        }
    return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna