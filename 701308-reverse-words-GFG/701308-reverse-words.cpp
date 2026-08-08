class Solution {
public:
    string reverseWords(string &s) {
        vector<string> words;
        string curr_word = "";
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.') {
                if (!curr_word.empty()) {
                    words.push_back(curr_word);
                    curr_word = "";
                }
            } else {
                curr_word += s[i];
            }
        }
        
        if (!curr_word.empty()) {
            words.push_back(curr_word);
        }
        
        string result = "";
        
        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i];
            if (i > 0) {
                result += ".";
            }
        }
        
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna