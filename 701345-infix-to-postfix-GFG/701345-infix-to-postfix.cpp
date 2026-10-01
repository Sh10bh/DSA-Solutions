class Solution {
private:
    int precedence(char c) {
        if (c == '^') {
            return 3;
        } else if (c == '/' || c == '*') {
            return 2;
        } else if (c == '+' || c == '-') {
            return 1;
        } else {
            return -1;
        }
    }

public:
    string infixToPostfix(string s) {
        stack<char> st;
        string ans;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                ans += c;
            } 
            else if (c == '(') {
                st.push('(');
            } 
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    st.pop();
                }
            } 
            else {
                while (!st.empty() && precedence(c) <= precedence(st.top())) {
                    if (c == '^' && st.top() == '^') {
                        break;
                    }
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna