class Solution {
public:
    string smallestPalindrome(string s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;

        string half = "", mid = "";
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) mid = string(1, 'a' + i);
            half += string(cnt[i] / 2, 'a' + i);
        }

        string rev = half;
        reverse(rev.begin(), rev.end());
        return half + mid + rev;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna