#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void replaceWithRank(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> v;
        
        for(int i = 0; i < n; i++) {
            v.push_back({arr[i], i});
        }
        
        sort(v.begin(), v.end());
        
        for(int i = 0; i < n; i++) {
            arr[v[i].second] = i;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna