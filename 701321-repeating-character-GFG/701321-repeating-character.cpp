class Solution {
  public:
    int repeatedCharacter(string& s) {
        // code here
        int n = s.length();
        int count[256] = {0};
        for(int i = 0; i < s.length(); i++){
            count[s[i]]++;
        }
        for(int i = 0 ; i < n; i++){
            if(count[s[i]] > 1){
                return i;
            }
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna