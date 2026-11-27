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
    Node *lca(Node *root, int n1, int n2) {
      //  code here
      if (root == NULL || root->data == n1 || root->data == n2)
        return root;
      Node *left = lca(root-> left, n1, n2);
      Node *right = lca(root-> right, n1, n2);

      if (left != NULL && right != NULL)
        return root;
      if (left != NULL)
        return left;

      return right;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna