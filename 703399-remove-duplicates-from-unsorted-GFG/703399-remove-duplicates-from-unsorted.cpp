class Solution {
public:
    vector<int> removeDuplicate(vector<int>& arr) {
        unordered_set<int> seen;
        vector<int> result;
        
        for (int i = 0; i < arr.size(); i++) {
            if (seen.find(arr[i]) == seen.end()) {
                seen.insert(arr[i]);
                result.push_back(arr[i]);
            }
        }
        
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna