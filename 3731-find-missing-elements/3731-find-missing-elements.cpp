#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        
        vector<bool> seen(101, false);
        for (int num : nums) {
            seen[num] = true;
        }
        
        vector<int> missing;
        for (int i = minNum + 1; i < maxNum; ++i) {
            if (!seen[i]) {
                missing.push_back(i);
            }
        }
        
        return missing;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna