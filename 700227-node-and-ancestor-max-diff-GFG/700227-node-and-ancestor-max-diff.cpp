class Solution {
public:
    int maxDiff(Node* root) {
        int max_diff = INT_MIN;
        getMin(root, max_diff);
        return max_diff;
    }

private:
    int getMin(Node* root, int& max_diff) {
        if (root == nullptr) {
            return INT_MAX;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return root->data;
        }

        int left_min = getMin(root->left, max_diff);
        int right_min = getMin(root->right, max_diff);

        int min_descendant = min(left_min, right_min);

        max_diff = max(max_diff, root->data - min_descendant);

        return min(root->data, min_descendant);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna