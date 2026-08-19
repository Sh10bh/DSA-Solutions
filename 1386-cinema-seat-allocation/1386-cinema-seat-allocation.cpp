class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved;
        for (auto& seat : reservedSeats) {
            reserved[seat[0]] |= (1 << seat[1]);
        }
        
        int max_families = (n - reserved.size()) * 2;
        
        for (auto& [row, mask] : reserved) {
            bool left = (mask & 60) == 0;
            bool right = (mask & 960) == 0;
            bool middle = (mask & 240) == 0;
            
            if (left && right) {
                max_families += 2;
            } else if (left || right || middle) {
                max_families += 1;
            }
        }
        
        return max_families;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna