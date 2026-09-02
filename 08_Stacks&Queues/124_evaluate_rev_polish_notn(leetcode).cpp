class Solution {
public:
    int applyOp(int a, int b, const string& token) {
        if (token == "+") return a + b;
        if (token == "-") return a - b;
        if (token == "*") return (long long)a * (long long)b;
        if (token == "/") return a / b;
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            // Check if the current token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                st.push(applyOp(a, b, token));
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};