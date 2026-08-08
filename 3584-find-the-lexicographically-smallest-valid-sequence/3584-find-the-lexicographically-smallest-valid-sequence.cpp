class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = first unmatched index in word2
        // after matching word2 from the right using word1[i...]
        vector<int> suf(n + 1);
        suf[n] = m;

        int j = m - 1;

        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            suf[i] = j + 1;
        }

        vector<int> ans;
        j = 0;
        bool changed = false;

        for (int i = 0; i < n && j < m; ++i) {

            // Exact match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Use our one allowed mismatch
            else if (!changed && suf[i + 1] <= j + 1) {
                ans.push_back(i);
                j++;
                changed = true;
            }
        }

        if (j != m)
            return {};

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna