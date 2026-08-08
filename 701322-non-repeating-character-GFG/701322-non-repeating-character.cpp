
class Solution {
  public:
    char nonRepeatingChar(string &s) {
        //  code here
        int arr[256] = {0};
        for(int i = 0 ; i < s.length(); i++){
            arr[s[i]]++;
        }
        for(int i =0; i < s.length(); i++){
            if(arr[s[i]] == 1){
                return s[i];
            }
        }
        return '$';
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna