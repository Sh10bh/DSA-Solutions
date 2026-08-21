class Solution {
public:
    int transform(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return -1;
        }

        int count[256] = {0};
        int n = s1.length();

        for (int i = 0; i < n; i++) {
            count[s1[i]]++;
            count[s2[i]]--;
        }

        for (int i = 0; i < 256; i++) {
            if (count[i] != 0) {
                return -1;
            }
        }

        int res = 0;
        int i = n - 1;
        int j = n - 1;

        while (i >= 0 && j >= 0) {
            if (s1[i] == s2[j]) {
                i--;
                j--;
            } else {
                res++;
                i--;
            }
        }

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna