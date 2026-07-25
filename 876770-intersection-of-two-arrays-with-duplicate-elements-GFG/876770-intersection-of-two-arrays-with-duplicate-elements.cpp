class Solution {
  public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> h;
        int x = a.size();
        int y = b.size();
        int i = 0;
        for(int i = 0; i < x; i++){
            h.insert(a[i]);
        }
        vector<int> res;
        for(int j = 0; j < y; j++){
            if(h.find(b[j]) != h.end()){
                res.push_back(b[j]);
                h.erase(b[j]);
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna