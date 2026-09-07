class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int n = arr.size();
        int count_5 = 0;
        int count_10 = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 5){
                count_5++;
            }
            else if(arr[i] == 10){
                if(count_5 > 0){
                    count_5--;
                    count_10++;
                }
                else{
                    return false;
                }
            }
            else if(arr[i] == 20){
                if(count_5 > 0 && count_10 > 0){
                    count_5--;
                    count_10--;
                }
                else if(count_5 >= 3){
                    count_5 -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna