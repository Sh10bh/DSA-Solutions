class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.length();
        int m = s.length();
        int j = 0;
        for(int i = 0; i < n && j < m; i++){
            if(t[i] == s[j]){
                j++;
            }
        }
        return (j==m);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna