/*  Structure of a Binary Tree
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
    int maxWidth(Node* root) {
        // code here
        int count = 0;
        if(root == NULL) return 0;
        queue<Node *> q;
        q.push(root);
        while(q.empty() == false){
            int n = q.size();
            count = max(count, n);
            for(int i = 0; i < n; i++){
                Node* curr = q.front();
                q.pop();
                if(curr-> left != NULL) q.push(curr-> left);
                if(curr-> right != NULL) q.push(curr-> right);
            }    
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna