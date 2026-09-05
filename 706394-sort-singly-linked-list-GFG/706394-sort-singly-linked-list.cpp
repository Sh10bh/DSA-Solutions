/* Structure of a Linked List Node
class Node
{
    int data;
    Node next;
    Node(int d) {
       data = d;
       next = nullptr;
    }
};*/
class Solution {
  public:
    Node* merge(Node* list1, Node* list2){
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;
        while (list1 != NULL && list2 != NULL) {
            if(list1-> data < list2-> data){
                temp-> next = list1;
                temp = list1;
                list1 = list1-> next;
            }
            else{
                temp-> next = list2;
                temp = list2;
                list2 = list2-> next;
            }
        }
        if (list1 != NULL) temp->next = list1;
        else temp->next = list2;
        Node* ans = dummyNode->next;
        delete dummyNode;
        return ans;
    }
    Node* sortLL(Node* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        Node* fast = head-> next;
        Node* slow = head;
        while(fast != NULL && fast-> next != NULL){
            fast = fast-> next-> next;
            slow = slow-> next;
        }
        Node* righthead = slow-> next;
        slow-> next = NULL;
        Node* lefthead = head;
        lefthead = sortLL(lefthead);
        righthead = sortLL(righthead);
        return merge(lefthead, righthead);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna