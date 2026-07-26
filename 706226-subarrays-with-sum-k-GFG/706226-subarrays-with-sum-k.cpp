class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> h;
        int n = arr.size();
        int sum = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum == k){
                count++;
            }
            int target = sum - k;
            if(h.find(target) != h.end()){
                count += h[target];
            }
            h[sum]++;
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna