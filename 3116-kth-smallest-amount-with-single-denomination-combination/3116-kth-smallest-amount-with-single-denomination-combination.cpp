#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int num_subsets = 1 << n;
        
        vector<long long> lcms(num_subsets, 1);
        vector<int> sign(num_subsets, 1);

        for (int i = 1; i < num_subsets; ++i) {
            int bit = __builtin_ctz(i);
            lcms[i] = std::lcm(lcms[i ^ (1 << bit)], (long long)coins[bit]);
            sign[i] = (__builtin_popcount(i) % 2 == 1) ? 1 : -1;
        }

        long long low = 1;
        long long high = 50000000000LL;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;

            for (int i = 1; i < num_subsets; ++i) {
                count += sign[i] * (mid / lcms[i]);
            }

            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna