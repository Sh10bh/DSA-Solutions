/* Structure of a Tree Node
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(root == NULL) return true;
        if(root ->left == NULL && root-> right == NULL) return true;
        int sum = 0;
        if(root-> left != NULL){
            sum += root-> left-> data;
        }
        if(root-> right != NULL){
            sum += root->right-> data;
        }
        return (root-> data == sum && isSumProperty(root-> left) && isSumProperty(root->right));
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna