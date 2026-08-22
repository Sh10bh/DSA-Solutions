class Solution {
public:
    int numberOfTurns(Node* root, int p, int q) {
        string path_p = "";
        string path_q = "";

        findPath(root, p, path_p);
        findPath(root, q, path_q);

        int i = 0;
        while (i < path_p.length() && i < path_q.length() && path_p[i] == path_q[i]) {
            i++;
        }

        string rem_p = path_p.substr(i);
        string rem_q = path_q.substr(i);

        reverse(rem_p.begin(), rem_p.end());
        string combined = rem_p + rem_q;

        if (combined.length() <= 1) {
            return -1;
        }

        int turns = 0;
        for (int j = 1; j < combined.length(); j++) {
            if (combined[j] != combined[j - 1]) {
                turns++;
            }
        }

        if (turns == 0) {
            return -1;
        }
        return turns;
    }

private:
    bool findPath(Node* root, int val, string& path) {
        if (!root) return false;
        if (root->data == val) return true;

        path.push_back('L');
        if (findPath(root->left, val, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, val, path)) return true;
        path.pop_back();

        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna