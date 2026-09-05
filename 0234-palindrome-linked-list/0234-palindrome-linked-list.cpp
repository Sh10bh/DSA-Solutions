/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast-> next != NULL){
            fast = fast-> next-> next;
            slow = slow -> next;
        }
        ListNode* temp = slow;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* after = temp-> next;
            temp-> next = prev;
            prev = temp;
            temp = after;
        }
        ListNode* x = head;
        ListNode* y = prev;
        while(y != NULL){
            if(x-> val != y-> val){
                return false;
            }
            x = x-> next;
            y = y-> next;
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna