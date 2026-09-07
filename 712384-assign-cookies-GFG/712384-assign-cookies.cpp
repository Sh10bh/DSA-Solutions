class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        // code here
        sort(greed.begin(), greed.end());
        sort(cookie.begin(), cookie.end());
        int n = greed.size();
        int m = cookie.size();
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            if(greed[i] <= cookie[j]){
                i = i + 1;
            }
            j = j + 1;
        }
        return i;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna