class Solution {
public:
    bool sumGame(string num) {
        int s1 = 0, s2 = 0;
        int c1 = 0, c2 = 0;
        int n = num.length();
        
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                c1++;
            } else {
                s1 += num[i] - '0';
            }
        }
        
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                c2++;
            } else {
                s2 += num[i] - '0';
            }
        }
        
        if ((c1 + c2) % 2 != 0) {
            return true;
        }
        
        return 2 * (s1 - s2) != 9 * (c2 - c1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna