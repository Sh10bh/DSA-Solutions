class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double, int>> ratio;
        for(int i = 0; i < val.size(); i++){
            double x = (double)val[i]/wt[i];
            ratio.push_back({x,i});
        }
        sort(ratio.rbegin(), ratio.rend());
        double value = 0.0;
        for(int i = 0; i < val.size(); i++){
            int idx = ratio[i].second;
            if(wt[idx] <= capacity){
                value += val[idx];
                capacity -= wt[idx];
            }
            else{
                value += ((double)val[idx]/(double)wt[idx]) * capacity;
                break;
            }
        }
        return value;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna