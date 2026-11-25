class Solution {
  public:
    int preIndex = 0;

    Node* cTree(vector<int>& inorder, vector<int>& preorder, int is, int ie) {
        if (is > ie) return NULL;

        Node* root = new Node(preorder[preIndex++]);

        int inIndex = is;
        for (int i = is; i <= ie; i++) {
            if (inorder[i] == root->data) {
                inIndex = i;
                break;
            }
        }

        root->left = cTree(inorder, preorder, is, inIndex - 1);
        root->right = cTree(inorder, preorder, inIndex + 1, ie);

        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        preIndex = 0;
        return cTree(inorder, preorder, 0, inorder.size() - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna