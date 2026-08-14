class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> res;
        queue<int> q;

        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                q.push(i);
            }
            while (!q.empty() && q.front() <= i - k) {
                q.pop();
            }
            if (i >= k - 1) {
                if (q.empty())
                    res.push_back(0);
                else
                    res.push_back(arr[q.front()]);
            }
        }

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna