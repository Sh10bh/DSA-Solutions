class Solution {
public:
    int findMax(int n) {
        string s = to_string(n);
        int len = s.size();
        long long best = n;
        int bestSum = 0;
        for (char c : s) bestSum += c - '0';

        for (int i = 0; i < len; i++) {
            if (s[i] == '0') continue;
            string cand = s.substr(0, i);
            cand += char(s[i] - 1);
            cand += string(len - i - 1, '9');
            long long val = stoll(cand);
            int sum = 0;
            for (char c : cand) sum += c - '0';
            if (sum > bestSum || (sum == bestSum && val > best)) {
                bestSum = sum;
                best = val;
            }
        }
        return (int)best;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna