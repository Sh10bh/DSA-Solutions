class Solution {
public:
    string compress(string &s) {
        int n = s.length();
        if (n == 0) return "";

        vector<int> lps(n, 0);
        int len = 0;
        int i = 1;

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        string ans = "";
        i = n - 1;

        while (i >= 0) {
            if (i % 2 != 0) {
                int half = (i + 1) / 2;
                int L = lps[i];
                int P = (i + 1) - L;

                if (L >= half && half % P == 0) {
                    ans.push_back('*');
                    i = half - 1;
                    continue;
                }
            }
            ans.push_back(s[i]);
            i--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna