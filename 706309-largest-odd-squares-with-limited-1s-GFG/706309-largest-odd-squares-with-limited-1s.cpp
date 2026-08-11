class Solution {
public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pref[i + 1][j + 1] = mat[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
            }
        }
        
        vector<int> ans;
        for (auto& q : queries) {
            int r_center = q[0];
            int c_center = q[1];
            
            int low = 0;
            int high = min({r_center, n - 1 - r_center, c_center, m - 1 - c_center});
            int best_r = -1;
            
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int r1 = r_center - mid;
                int c1 = c_center - mid;
                int r2 = r_center + mid;
                int c2 = c_center + mid;
                
                int ones = pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
                
                if (ones <= k) {
                    best_r = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            
            if (best_r == -1) {
                ans.push_back(-1);
            } else {
                ans.push_back(2 * best_r + 1);
            }
        }
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna