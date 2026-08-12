class Solution {
public:
    vector<int> findWays(vector<vector<int>>& grid) {
        int n = grid.size();
        int mod = 1e9 + 7;
        
        vector<vector<int>> ways(n, vector<int>(n, 0));
        vector<vector<int>> maxAdv(n, vector<int>(n, 0));
        
        ways[0][0] = 1;
        maxAdv[0][0] = grid[0][0];
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                
                if (i > 0 && ways[i - 1][j] > 0 && (grid[i - 1][j] == 2 || grid[i - 1][j] == 3)) {
                    ways[i][j] = (ways[i][j] + ways[i - 1][j]) % mod;
                    maxAdv[i][j] = max(maxAdv[i][j], maxAdv[i - 1][j] + grid[i][j]);
                }
                
                if (j > 0 && ways[i][j - 1] > 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 3)) {
                    ways[i][j] = (ways[i][j] + ways[i][j - 1]) % mod;
                    maxAdv[i][j] = max(maxAdv[i][j], maxAdv[i][j - 1] + grid[i][j]);
                }
            }
        }
        
        if (ways[n - 1][n - 1] == 0) {
            return {0, 0};
        }
        
        return {ways[n - 1][n - 1], maxAdv[n - 1][n - 1]};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna