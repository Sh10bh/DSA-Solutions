class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int left = 0;
        int right = arr.size() - 1;
        int max_left = 0;
        int max_right = 0;
        int total = 0;
        while(left < right){
            if(arr[left] <= arr[right]){
                if(arr[left] >= max_left){
                    max_left = arr[left];
                }
                else{
                    total += max_left - arr[left];
                }
                left++;
            }
            else {
                if (arr[right] >= max_right) {
                    max_right = arr[right];
                } else {
                    total += (max_right - arr[right]);
                }
                right--;
            }
        }
        return total;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna