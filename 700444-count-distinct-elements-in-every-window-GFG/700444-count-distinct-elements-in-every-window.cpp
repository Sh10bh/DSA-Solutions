class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        vector<int> res;
        unordered_map<int, int> freq;
        for(int i = 0; i < k; i++){
            freq[arr[i]]++;
        }
        res.push_back(freq.size());
        for(int i = k ; i < arr.size() ; i++){
            freq[arr[i]]++;
            freq[arr[i - k]]--;
            if(freq[arr[i-k]] == 0){
                freq.erase(arr[i - k]);
            }
            res.push_back(freq.size());
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna