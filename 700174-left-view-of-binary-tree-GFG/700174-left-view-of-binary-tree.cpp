/* Structure of Binary Tree Node
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
    vector<int> leftView(Node *root) {
        vector<int> res;
        if(root == NULL) return res;
        queue<Node *> q;
        q.push(root);
        while(q.empty() == false){
            int n = q.size();
            for(int i = 0; i < n; i++){
                Node* curr = q.front();
                q.pop();
                if(i == 0){
                    res.push_back(curr-> data);
                }
                if(curr-> left != NULL) q.push(curr-> left);
                if(curr-> right != NULL) q.push(curr-> right);
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna