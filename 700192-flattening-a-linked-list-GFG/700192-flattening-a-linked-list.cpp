class Solution {
public:
    Node* merge(Node* a, Node* b) {
        Node dummy(-1);
        Node* temp = &dummy;

        while (a != NULL && b != NULL) {
            if (a->data < b->data) {
                temp->bottom = a;
                a = a->bottom;
            } else {
                temp->bottom = b;
                b = b->bottom;
            }
            temp = temp->bottom;
            temp->next = NULL;
        }

        if (a != NULL) temp->bottom = a;
        else temp->bottom = b;

        Node* scrub = temp->bottom;
        while (scrub != NULL) {
            scrub->next = NULL;
            scrub = scrub->bottom;
        }

        return dummy.bottom;
    }

    Node* flatten(Node* root) {
        if (root == NULL || root->next == NULL) {
            return root;
        }

        Node* slow = root;
        Node* fast = root->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* mid = slow->next;
        slow->next = NULL;

        Node* left = flatten(root);
        Node* right = flatten(mid);

        return merge(left, right);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna