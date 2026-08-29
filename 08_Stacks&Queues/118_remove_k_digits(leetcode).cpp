class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            // Move condition directly into while loop to avoid infinite loop
            while (!st.empty() && k != 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (k != 0 && !st.empty()) {
            st.pop();
            k--;
        }

        if (st.empty()) {
            return "0";
        }

        // Build result from stack
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int start = 0;
        while (start < ans.size() && ans[start] == '0') {
            start++;
        }
        ans = ans.substr(start);

        return ans.empty() ? "0" : ans;
    }
};