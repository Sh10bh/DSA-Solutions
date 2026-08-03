#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long int maxSumWithK(vector<int>& a, long long int k) {
        long long int n = a.size();
        if (n < k) return 0;

        vector<long long int> maxSum(n);
        maxSum[0] = a[0];
        
        for (long long int i = 1; i < n; i++) {
            maxSum[i] = max((long long int)a[i], maxSum[i - 1] + a[i]);
        }

        long long int current_k_sum = 0;
        for (long long int i = 0; i < k; i++) {
            current_k_sum += a[i];
        }

        long long int max_ans = current_k_sum;

        for (long long int i = k; i < n; i++) {
            current_k_sum = current_k_sum + a[i] - a[i - k];
            long long int current_ans = current_k_sum;
            
            if (maxSum[i - k] > 0) {
                current_ans += maxSum[i - k];
            }
            
            max_ans = max(max_ans, current_ans);
        }

        return max_ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna