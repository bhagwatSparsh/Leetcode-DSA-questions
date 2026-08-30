class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();
        stack<int> st;
        

        for (int i=0;i<n;i++){
            if (st.empty() || st.top()!=s[i]){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        string res="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();

        }
        reverse(res.begin(), res.end());
        return res;

        
    }
};