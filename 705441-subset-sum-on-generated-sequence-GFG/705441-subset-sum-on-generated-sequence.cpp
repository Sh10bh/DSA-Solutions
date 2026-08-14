class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        vector<long long> P;
        P.push_back(s);
        long long current_sum = s;

        for (int i = 0; i < arr.size(); ++i) {
            long long next_val = current_sum + arr[i];

            if (next_val > x) {
                break;
            }

            P.push_back(next_val);
            current_sum += next_val;
        }

        for (int i = P.size() - 1; i >= 0; --i) {
            if (x >= P[i]) {
                x -= P[i];
            }
        }

        return x == 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna