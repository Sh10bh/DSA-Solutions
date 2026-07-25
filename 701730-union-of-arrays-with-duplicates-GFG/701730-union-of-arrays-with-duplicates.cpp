
class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        set<int> h;
        int x = a.size();
        int y = b.size();
        for(int i = 0; i < x; i++){
            h.insert(a[i]);
        }
        for(int j = 0; j < y; j++){
            h.insert(b[j]);
        }
        vector<int> res;
        for(auto e : h){
            res.push_back(e);
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna