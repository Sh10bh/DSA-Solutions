/*
class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int cycleStart(Node* head) {
        // code here
        Node* fast = head;
        Node* slow = head;
        while(fast != NULL && fast-> next != NULL){
            slow = slow-> next;
            fast = fast-> next-> next;
            if(fast == slow){
                slow = head;
                while(fast != slow){
                    slow = slow-> next;
                    fast = fast-> next;
                }
                return fast-> data;
            }
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna