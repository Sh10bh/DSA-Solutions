class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        const int CHAR = 256;
        if(s1.length() != s2.length()){
            return false;
        }
        int count[CHAR] = {0};
        for(int i = 0 ; i < s1.length(); i++){
            count[s1[i]]++;
            count[s2[i]]--;
        }
        for(int i = 0 ; i < CHAR; i++){
            if(count[i] != 0){
                return false;
            }
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna