/* Structure of binary tree node
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
    int checkHeight(Node *root) {
      if (root == NULL)
        return 0;

      int lh = checkHeight(root->left);
      if (lh == -1)
        return -1;

      int rh = checkHeight(root->right);
      if (rh == -1)
        return -1;

      if (abs(lh - rh) > 1)
        return -1;

      return 1 + max(lh, rh);
    }

    bool isBalanced(Node *root) { return checkHeight(root) != -1; }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna