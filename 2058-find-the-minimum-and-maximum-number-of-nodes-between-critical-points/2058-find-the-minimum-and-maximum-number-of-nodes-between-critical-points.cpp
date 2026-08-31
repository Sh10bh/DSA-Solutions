class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;
        
        int first_cp = -1;
        int last_cp = -1;
        int min_dist = INT_MAX;
        
        while (curr->next) {
            ListNode* nxt = curr->next;
            
            if ((curr->val > prev->val && curr->val > nxt->val) || 
                (curr->val < prev->val && curr->val < nxt->val)) {
                
                if (first_cp == -1) {
                    first_cp = idx;
                } else {
                    min_dist = min(min_dist, idx - last_cp);
                }
                last_cp = idx;
            }
            
            prev = curr;
            curr = nxt;
            idx++;
        }
        
        if (min_dist == INT_MAX) {
            return {-1, -1};
        }
        
        return {min_dist, last_cp - first_cp};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna