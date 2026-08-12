class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_profit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < min_price){
                min_price = prices[i];
            }
            if(prices[i] - min_price > max_profit){
                max_profit = prices[i] - min_price;
            }
        }
        return max_profit;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna