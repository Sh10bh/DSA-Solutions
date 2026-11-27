/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int diameter(Node *root) {
      // code here
      if (root == NULL)
        return 0;
      int d1 = height(root->left) + height(root->right);
      int d2 = diameter(root->left);
      int d3 = diameter(root->right);
      return max(d1, max(d2, d3));
    }
    int height(Node *root) {
      if (root == NULL)
        return 0;
        return  1 + max(height(root-> left), height(root-> right));
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna