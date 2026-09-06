/*Structure of the doubly linked list  Node 
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/

class Solution {
  public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        // code here
        Node* temp = head;
        while(temp != NULL){
            if(temp-> data == x){
                if(temp == head){
                    head = head-> next;
                }
                Node* after = temp-> next;
                Node* before = temp-> prev;
                if(after != NULL){
                    after-> prev = before;
                }
                if(before != NULL){
                    before-> next = after;
                }
                delete temp;
                temp = after;
            }
            else{
               temp = temp-> next; 
            }
        }
        return head;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna