class Solution {
public:
    int solve(int n, string s) {
        int occupied = 0;
        int rejected = 0;
        vector<int> status(26, 0);

        for (char c : s) {
            int id = c - 'A';

            if (status[id] == 0) {
                if (occupied < n) {
                    occupied++;
                    status[id] = 1;
                } else {
                    rejected++;
                    status[id] = 2;
                }
            } else if (status[id] == 1) {
                occupied--;
            }
        }

        return rejected;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna