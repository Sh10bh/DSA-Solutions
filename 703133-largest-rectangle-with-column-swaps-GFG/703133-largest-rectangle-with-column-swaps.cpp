class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return 0;

        int r = mat.size();
        int c = mat[0].size();

        vector<int> hist(c, 0);
        int max_area = 0;

        for (int i = 0; i < r; ++i) {
            // 1. Update the histogram heights for the current row
            for (int j = 0; j < c; ++j) {
                if (mat[i][j] == 1) {
                    hist[j] += 1;
                } else {
                    hist[j] = 0;
                }
            }

            // 2. Sort a copy of the heights in descending order
            vector<int> curr_row = hist;
            sort(curr_row.begin(), curr_row.end(), greater<int>());

            // 3. Calculate the maximum area for the current configuration
            for (int k = 0; k < c; ++k) {
                // If the height is 0, subsequent areas will also be 0
                if (curr_row[k] == 0) break; 

                int current_area = curr_row[k] * (k + 1);
                max_area = max(max_area, current_area);
            }
        }

        return max_area;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna