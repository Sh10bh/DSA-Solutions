/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        // code here
        if(headRef == NULL) return NULL;
        Node* temp = headRef;
        while(temp-> next != NULL){
            if (temp->data == temp->next->data) {
                Node* duplicate = temp->next;
                temp->next = duplicate->next;
                if (duplicate->next != NULL) {
                    duplicate->next->prev = temp;
                }
                delete duplicate;
            }
            else{
                temp = temp-> next;
            }
        }
        return headRef;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna