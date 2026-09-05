/*
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }

}; */

class Solution {
  public:
    int getMiddle(Node* head) {
        // code here
        Node* temp = head;
            int count = 0;
            while(temp != NULL){
                count++;
                temp = temp-> next;
            }
            int x = count/2 ;
            count = 0;
            temp = head;
            while(x > 0){
                temp = temp-> next;
                x--;
            }
            return temp-> data;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna