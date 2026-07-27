class Solution {
public:
    Node* buildUtil(vector<int>& pre, unordered_map<int,int>& posInMirror,
                     int* preIndex, int l, int h, int n) {
        if (*preIndex >= n || l > h)
            return NULL;

        Node* root = new Node(pre[*preIndex]);
        (*preIndex)++;

        if (l == h)
            return root;

        int i = posInMirror[pre[*preIndex]];

        root->left  = buildUtil(pre, posInMirror, preIndex, i, h, n);
        root->right = buildUtil(pre, posInMirror, preIndex, l + 1, i - 1, n);

        return root;
    }

    Node* constructBinaryTree(vector<int>& pre, vector<int>& preMirror) {
        int n = pre.size();
        unordered_map<int,int> posInMirror;
        for (int i = 0; i < n; i++)
            posInMirror[preMirror[i]] = i;

        int preIndex = 0;
        return buildUtil(pre, posInMirror, &preIndex, 0, n - 1, n);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna