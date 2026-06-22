// brute force soln:

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        stack<char> st;

        for (char ch: s){
            if (ch==')'){
                st.pop();
            }
            if (!st.empty()){
                ans+=ch;
            }
            if (ch=='('){
                st.push(ch);
            }
        }
        return ans;
        
    }
};

// optimal approach:

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int cnt=0;

        for (char ch: s){
            if (ch==')'){
                cnt--;
            }
            if (cnt>0){
                ans+=ch;
            }
            if (ch=='('){
                cnt++;
            }
        }
        return ans;
        
    }
};