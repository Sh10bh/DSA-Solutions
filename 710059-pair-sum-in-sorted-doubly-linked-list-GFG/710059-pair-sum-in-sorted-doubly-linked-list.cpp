/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  public:
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        // code here
        vector<vector<int>> ans;
        if(head == NULL) return ans;
        Node* temp = head;
        while(temp-> next != NULL){
            temp = temp-> next;
        }
        Node* right = temp;
        Node* left = head;
        while(left != NULL && right != NULL && left != right && left->prev != right){
            if(left-> data + right->data == target){
                ans.push_back({left-> data, right-> data});
                left = left-> next;
                right = right-> prev;
            }
            else if(left-> data + right-> data > target){
                right = right-> prev;
            }
            else{
                left = left-> next;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna