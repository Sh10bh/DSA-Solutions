struct Node {
    int maxLen;
    int prefLen;
    int suffLen;
    int size;
    char prefChar;
    char suffChar;

    Node() {
        maxLen = prefLen = suffLen = size = 0;
        prefChar = suffChar = ' ';
    }
};

class SegmentTree {
    vector<Node> tree;
    string s;
    int n;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.size = left.size + right.size;
        res.prefChar = left.prefChar;
        res.suffChar = right.suffChar;
        
        res.prefLen = left.prefLen;
        if (left.prefLen == left.size && left.prefChar == right.prefChar) {
            res.prefLen += right.prefLen;
        }
        
        res.suffLen = right.suffLen;
        if (right.suffLen == right.size && right.suffChar == left.suffChar) {
            res.suffLen += left.suffLen;
        }
        
        res.maxLen = max(left.maxLen, right.maxLen);
        if (left.suffChar == right.prefChar) {
            res.maxLen = max(res.maxLen, left.suffLen + right.prefLen);
        }
        
        return res;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node].maxLen = tree[node].prefLen = tree[node].suffLen = tree[node].size = 1;
            tree[node].prefChar = tree[node].suffChar = s[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char c) {
        if (start == end) {
            tree[node].prefChar = tree[node].suffChar = c;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, c);
        } else {
            update(2 * node + 1, mid + 1, end, idx, c);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    SegmentTree(string str) {
        s = str;
        n = s.length();
        tree.resize(4 * n + 1);
        if (n > 0) {
            build(1, 0, n - 1);
        }
    }
    
    void update(int idx, char c) {
        update(1, 0, n - 1, idx, c);
    }
    
    int getMaxLen() {
        return tree[1].maxLen;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        vector<int> ans;
        ans.reserve(queryIndices.size());
        
        for (int i = 0; i < queryIndices.size(); ++i) {
            st.update(queryIndices[i], queryCharacters[i]);
            ans.push_back(st.getMaxLen());
        }
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna