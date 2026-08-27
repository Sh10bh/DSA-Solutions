class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        int best_i = -1;
        char best_c = 0;
        vector<int> best_remaining;
        
        for (int i = 0; i < s.length(); i++) {
            // 1. Look for a valid character strictly greater than target[i]
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (count[c] > 0) {
                    best_i = i;
                    best_c = c + 'a';
                    best_remaining = count;
                    break;
                }
            }
            
            // 2. Attempt to perfectly match target[i] to continue the prefix
            if (count[target[i] - 'a'] > 0) {
                count[target[i] - 'a']--;
            } else {
                break; // Cannot extend the matching prefix any further
            }
        }
        
        // If we never found a point to diverge and be strictly greater
        if (best_i == -1) {
            return "";
        }
        
        // 3. Reconstruct the optimal string
        string ans = target.substr(0, best_i);
        ans += best_c;
        best_remaining[best_c - 'a']--;
        
        for (int c = 0; c < 26; c++) {
            if (best_remaining[c] > 0) {
                ans += string(best_remaining[c], c + 'a');
            }
        }
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna