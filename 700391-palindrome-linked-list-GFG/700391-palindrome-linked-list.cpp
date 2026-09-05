/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        //  code here
        Node* fast = head;
        Node* slow = head;
        while(fast != NULL && fast-> next != NULL){
            fast = fast-> next-> next;
            slow = slow-> next;
        }
        Node* temp = slow;
        Node* prev = NULL;
        while(temp != NULL){
            Node* front = temp-> next;
            temp-> next = prev;
            prev = temp;
            temp = front;
        }
        Node* x = head;
        Node* y = prev;
        while(y != NULL){
            if(x-> data != y-> data){
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