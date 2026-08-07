class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int n = s2.length();
        int m = s1.length();
        int j = 0;
        for(int i = 0; i < n && j < m; i++){
            if(s2[i] == s1[j]){
                j++;
            }
        }
        return (j==m);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna