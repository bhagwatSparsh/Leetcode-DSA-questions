#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            // 1. If opening bracket, push to stack
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } 
            // 2. If closing bracket, validate and pop
            else {
                if (st.empty()) {
                    return false;
                }

                char top = st.top();
                
                // Compare current closing bracket with top opening bracket
                if ((s[i] == ')' && top == '(') || 
                    (s[i] == '}' && top == '{') || 
                    (s[i] == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        
        // Stack must be empty if all brackets were closed
        return st.empty();
    }
};