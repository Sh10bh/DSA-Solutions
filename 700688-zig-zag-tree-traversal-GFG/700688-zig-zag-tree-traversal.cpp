class Solution {
  public:
    vector<int> zigZagTraversal(Node *root) {
      vector<int> res;
      if (root == NULL)
        return res;
      queue<Node *> q;
      q.push(root);
      bool leftToRight = true;
      while (!q.empty()) {
        int n = q.size();
        vector<int> level(n);
        for (int i = 0; i < n; i++) {
          Node *curr = q.front();
          q.pop();

          int index = leftToRight ? i : (n - 1 - i);
          level[index] = curr->data;

          if (curr->left != NULL)
            q.push(curr->left);
          if (curr->right != NULL)
            q.push(curr->right);
        }
        for (int val : level) {
          res.push_back(val);
        }
        leftToRight = !leftToRight;
      }
      return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna