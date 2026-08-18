#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        if (k == 1) {
            int ans = -1;
            for (auto const& [num, count] : freq) {
                if (count == 1) {
                    ans = max(ans, num);
                }
            }
            return ans;
        }
        
        int ans = -1;
        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna